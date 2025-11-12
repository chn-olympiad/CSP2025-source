#include <bits/stdc++.h>
#define fr(x)\
	freopen(#x".in","r",stdin);\
	freopen(#x".out","w",stdout);

using std::cin;
typedef long long ll;
constexpr int N=20,mod=998244353;
int n,m;
int s[N],c[N];
int f[1<<N][N]; // S, choosed

int main()
{
	fr(employ)
	cin.tie(nullptr)->sync_with_stdio(false);
	cin>>n>>m;
	if(n>20)return 0;
	for(int i=1;i<=n;i++)
	{
		char o;
		cin>>o;
		s[i]=(o=='1');
	}
	for(int i=1;i<=n;i++)cin>>c[i];
	f[0][0]=1;
	for(int i=0;i<(1<<n);i++)
	{
		int cnt=__builtin_popcount(i);
		for(int j=0;j<=cnt;j++) // ok cnt
		{
			for(int k=1;k<=n;k++)if(((i>>(k-1))&1)==0)
			{
				int ok=0;
				if(cnt-j<c[k]&&s[cnt+1])ok=1;
				f[i|(1<<(k-1))][j+ok]+=f[i][j];
				f[i|(1<<(k-1))][j+ok]%=mod;
			}
		}
	}
	int ans=0;
	for(int i=m;i<=n;i++)(ans+=f[(1<<n)-1][i])%=mod;
	printf("%d",ans);
	return 0;
}
