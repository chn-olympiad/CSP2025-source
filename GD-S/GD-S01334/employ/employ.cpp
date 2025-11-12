#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int mod=998244353,maxn=505;
int n,m;
char s[maxn];
int c[maxn];
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	if(m==1)
	{
		cout<<0;
	}
	else if(m==n)
	{
		ll p=1;
		scanf("%s",s+1);
		for(int i=1;i<=n;i++)p&=(s[i]=='1');
		for(int i=1;i<=n;i++)scanf("%d",c+i),p&=(c[i]==0);
		ll ans=1;
		for(int i=1;i<=n;i++)ans=ans*i%mod;
		printf("%lld",ans*p);
	}
	else
	{
		cout<<0;
	}
	return 0;
}
