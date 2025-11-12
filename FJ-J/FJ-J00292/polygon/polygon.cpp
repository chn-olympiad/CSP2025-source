#include <cstdio>
#include <algorithm>
using namespace std;

const int mod=998244353;
const int Vmax=5001;

int a[5009];
int f[2][Vmax+9];

int main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	
	int n;
	scanf("%d", &n);
	for (int i=1; i<=n; i++)	scanf("%d", &a[i]);
	
	sort(a+1, a+n+1);
	int ans=0;
	f[0][0]=1;
	for (int i=1; i<=n; i++){
		for (int j=a[i]+1; j<=Vmax; j++)
			ans=(ans+f[(i-1)&1][j])%mod;
		
		for (int j=0; j<=Vmax; j++)	f[i&1][j]=f[(i-1)&1][j];
		for (int j=0; j<=Vmax; j++)
			f[i&1][min(j+a[i], Vmax)]=(f[i&1][min(j+a[i], Vmax)]+f[(i-1)&1][j])%mod;
	}
	
	printf("%d\n", ans);
	return 0;
}
