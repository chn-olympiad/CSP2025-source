#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5005;
const ll Mod=998244353;

int n, a[N];
ll f[2][50005][105], ans=0;
void upd(ll &to, ll from)
{
	to=to+from;
	if (to>=Mod) to-=Mod;
}
int main()
{
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	
	scanf("%d", &n);
	for (int i=1; i<=n; i++) scanf("%d", &a[i]);
	sort(a+1, a+1+n);
	
	f[0][0][0]=1;
	
	int sum=0, mx=0;
	for (int i=0, op=1; i<=n; i++, op^=1)
	{
		for (int j=0; j<=sum; j++) for (int k=0; k<=mx; k++) f[op][j][k]=0;
		
		sum+=a[i], mx=max(mx, a[i]);
		for (int j=0; j<=sum; j++)
			for (int k=0; k<=mx; k++)
			{
				upd(f[op][j+a[i+1]][max(k, a[i+1])], f[op^1][j][k]);
				upd(f[op][j][k], f[op^1][j][k]);
			}
	}
	
	for (int j=0; j<=sum; j++) for (int k=0; k<=mx; k++) if (j>2*k) upd(ans, f[n&1][j][k]);
	
	printf("%lld", ans);	
	return 0;
} 
