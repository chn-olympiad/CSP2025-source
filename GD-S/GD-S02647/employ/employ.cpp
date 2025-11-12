#include<bits/stdc++.h>
using namespace std;
#define int long long
#define N 200000
#define mod 998244353
inline int read()
{
	int res=0;
	char x=getchar();
	while(x<'0'||x>'9')x=getchar();
	while(x>='0'&&x<='9')res=res*10+(x-'0'),x=getchar();
	return res;
}
int n,m;
string s;
int c[N],p[N];
signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	n=read(),m=read();
	cin>>s;
	for(int i=1;i<=n;i++)c[i]=read(),p[i]=i;
	int ans=0;
	if(n<=18)
	{
		do
		{
			int tot=0,cnt=0;
			for(int i=1;i<=n;i++)
			{
				if(c[p[i]]<=cnt||s[i-1]=='0')
				{
					cnt++;
					continue;
				}
				tot++;
			}
			if(tot>=m)
			{
				ans++;
				ans%=mod;
			}
		}while(next_permutation(p+1,p+n+1));
		printf("%lld\n",ans%mod);
		return 0;
	}
	int res=1;
	for(int i=1;i<=n;i++)
		res=res*i%mod;
	printf("%lld\n",res);
}
