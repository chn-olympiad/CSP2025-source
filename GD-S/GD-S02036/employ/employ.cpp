#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=510,mod=998244353;
int n,m;
string s;
int c[N];
namespace case1
{
	int f[(1<<18)+5][20];
	int main()
	{
		f[0][0]=1;
		for(int S=0;S<(1<<n);S++)
		{
			int tot=__builtin_popcount(S);
			for(int i=0;i<=tot;i++)
			{
				for(int j=1,u;j<=n;j++)
				{
					if((S>>(j-1))&1)continue;
					if(tot-i<c[j])u=1;
					else u=0;
					if(s[tot+1]=='0')u=0;
					f[S^(1<<(j-1))][i+u]=(f[S^(1<<(j-1))][i+u]+f[S][i])%mod;
				}
			}
		}
		int ans=0;
		for(int i=m;i<=n;i++)ans=(ans+f[(1<<n)-1][i])%mod;
		cout<<ans;
		return 0;
	}
}
signed main()
{
//	system("fc employ2.ans employ.out");return 0;
	freopen("employ.in","r",stdin),freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m>>s,s="#"+s;
	for(int i=1;i<=n;i++)cin>>c[i];
	if(n<=18)return case1::main();
	cout<<0;
	return 0;
}
