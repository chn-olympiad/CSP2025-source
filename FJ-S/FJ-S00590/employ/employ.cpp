#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define N 19
#define MOD 998244353
using namespace std;
inline void add(int &x,int y){x+=y,x-=x>=MOD?MOD:0;}
int n,m,a[N],f[1<<N][N],ans;
char ch[N];
signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%lld%lld%s",&n,&m,ch+1);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	f[0][0]=1;
	for(int S=0;S<(1<<n);S++)
	{
		int pc=__builtin_popcountll(S);
		for(int i=0;i<=pc;i++)
		{
			for(int j=1;j<=n;j++)if(!(S>>(j-1)&1))
			{
				if(i>=a[j])add(f[S|(1ll<<j-1)][i+1],f[S][i]);
				else if(ch[pc+1]=='0')add(f[S|(1ll<<j-1)][i+1],f[S][i]);
				else add(f[S|(1ll<<j-1)][i],f[S][i]);
			}
		}
	}
	for(int i=0;i<=n-m;i++)add(ans,f[(1<<n)-1][i]);
	printf("%lld\n",ans);
	return 0;
}
