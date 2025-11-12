#include <bits/stdc++.h>
using namespace std;
const int mod=998244353;
inline int Mod(int x) { return x<0 ? x+mod : (x>=mod ? x-mod : x); }
inline void adm(int &x,int y) { x=Mod(x+y); }
const int N=18;
int n,m;
string state; int lim[N];
int f[N][1<<N][N];
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> n >> m;
	cin >> state;
	for (int i=0;i<n;i++) cin >> lim[i];
	
	f[0][0][0]=1;
	for (int i=0;i<n;i++)
	{
		for (int S=0;S<(1<<n);S++)
		{
			if (__builtin_popcount(S)!=i) continue;
			for (int j=0;j<=i;j++)
			{
				if (!f[i][S][j]) continue;
				for (int u=0;u<n;u++)
				{
					if (S>>u&1) continue;
					bool flag=(state[i]=='0' || j>=lim[u]);
					adm(f[i+1][S|(1<<u)][j+flag],f[i][S][j]);
				}
			}
		}
	}
	
	int ans=0;
	for (int j=0;j<=n-m;j++) adm(ans,f[n][(1<<n)-1][j]);
	cout << ans << "\n";
	
	return 0;
} 

/*

3 2
101
1 1 2

10 5
1101111011
6 0 4 2 1 2 5 4 3 3

*/
