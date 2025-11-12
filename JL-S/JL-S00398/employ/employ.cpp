#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int s[510];
int c[510];
int f[510];
int ans;
int cnt;
const int mod=998244353;
signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%1lld",&s[i]);
	}
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&c[i]);
	}
	for(int i=1;i<=n;i++)
	{
		f[i]=i;
	}
	for(int i=1;i<=n;i++)
	{
		do
		{
			if(c[f[i]]-cnt>=0||s[f[i]]==1)
			{
				ans++;
			}
			if(s[f[i]]==0||c[f[i]]<0)
			{
				cnt++;
			}
		}while(next_permutation(f+1,f+n+1));
	}
	printf("%lld\n",ans%mod);
	return 0;
}