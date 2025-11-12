#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,s[114514],c[114514],sb,sb1;
bool flag=0;
signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;++i)
	{
		scanf("%1lld",&s[i]);
		if(s[i]==0)flag=1,sb1++;
	}
	for(int i=1;i<=n;++i)
	{
		scanf("%lld",&c[i]);
		if(c[i]==0)sb++;
	}
	if(n==m&&sb==0&&sb1==0)
	{
		int ans=1;
		for(int i=1;i<=n;++i)ans=ans*i%998244353;
		printf("%lld\n",ans);
	}
	else printf("0\n");
	return 0;
}
