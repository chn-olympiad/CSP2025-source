#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int a[500009], s[500009];
int lst[(1<<20)+9];
int f[500009];

int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	
	int n, k;
	scanf("%d%d", &n, &k);
	for (int i=1; i<=n; i++)	scanf("%d", &a[i]);
	
	for (int i=1; i<=n; i++)	s[i]=s[i-1]^a[i];
	memset(lst, 0xff, sizeof lst);
	lst[0]=0;
	for (int i=1; i<=n; i++){
		f[i]=f[i-1];
		if (lst[s[i]^k]!=-1)
			f[i]=max(f[i], f[lst[s[i]^k]]+1);
		lst[s[i]]=i;
	}
	
	printf("%d\n", f[n]);
	return 0;
}
