extern int HookDirectDraw(HMODULE, int);
extern int HookDDProxy(HMODULE, int);
extern int HookDirect3D(HMODULE, int);
extern int HookDirect3D7(HMODULE, int);
extern void HookOle32(HMODULE);
extern void HookGDI32(HMODULE);
extern void HookDirectInput(HMODULE, int);
extern void HookDirectInput8(HMODULE, int);
extern void HookDirectSound(HMODULE);
extern void HookImeLib(HMODULE);
extern void HookKernel32(HMODULE);
extern void HookUser32(HMODULE);
extern void HookWinMM(HMODULE, char *libname);
extern void HookAdvApi32(HMODULE);
extern void HookImagehlp(HMODULE);
extern void HookSmackW32(HMODULE);
extern void HookAVIFil32(HMODULE);
extern void HookComDlg32(HMODULE);

extern void InitPosition(int, int, int, int, int, int);
//void InitWindowPos(int, int, int, int);
extern LPCSTR ProcToString(LPCSTR proc);
extern HRESULT HookDxDiag(REFIID, LPVOID FAR*);

extern FARPROC Remap_ddraw_ProcAddress(LPCSTR, HMODULE);
extern FARPROC Remap_d3d7_ProcAddress(LPCSTR, HMODULE);
extern FARPROC Remap_d3d8_ProcAddress(LPCSTR, HMODULE);
extern FARPROC Remap_d3d9_ProcAddress(LPCSTR, HMODULE);
extern FARPROC Remap_d3d10_ProcAddress(LPCSTR, HMODULE);
extern FARPROC Remap_d3d10_1_ProcAddress(LPCSTR, HMODULE);
extern FARPROC Remap_d3d11_ProcAddress(LPCSTR, HMODULE);
extern FARPROC Remap_gl_ProcAddress(LPCSTR, HMODULE);
extern FARPROC Remap_smack_ProcAddress(LPCSTR, HMODULE);
extern FARPROC Remap_user32_ProcAddress(LPCSTR, HMODULE);
extern FARPROC Remap_GDI32_ProcAddress(LPCSTR, HMODULE);
extern FARPROC Remap_kernel32_ProcAddress(LPCSTR, HMODULE);
extern FARPROC Remap_ole32_ProcAddress(LPCSTR, HMODULE);
extern FARPROC Remap_trust_ProcAddress(LPCSTR, HMODULE);
extern FARPROC Remap_WinMM_ProcAddress(LPCSTR, HMODULE);
extern FARPROC Remap_ImeLib_ProcAddress(LPCSTR, HMODULE);
extern FARPROC Remap_vfw_ProcAddress(LPCSTR, HMODULE);
extern FARPROC Remap_AdvApi32_ProcAddress(LPCSTR, HMODULE);
extern FARPROC Remap_Glide_ProcAddress(LPCSTR, HMODULE);
extern FARPROC Remap_Imagehlp_ProcAddress(LPCSTR, HMODULE);
extern FARPROC Remap_DInput_ProcAddress(LPCSTR, HMODULE);
extern FARPROC Remap_DInput8_ProcAddress(LPCSTR, HMODULE);

typedef enum {
	HOOK_IAT_CANDIDATE = 0,
	HOOK_HOT_CANDIDATE,
	HOOK_IAT_LINKED,
	HOOK_HOT_LINKED
} HookEntry_Status;


typedef struct {
	HookEntry_Status HookStatus;
	char *APIName;
	FARPROC OriginalAddress;
	FARPROC *StoreAddress;
	FARPROC HookerAddress;
} HookEntry_Type;

extern FARPROC RemapLibrary(LPCSTR, HMODULE, HookEntry_Type *);
extern void HookLibrary(HMODULE, HookEntry_Type *, char *);
extern void PinLibrary(HookEntry_Type *, char *);
extern void HookLibInit(HookEntry_Type *);
extern BOOL IsHotPatched(HookEntry_Type *, char *);
