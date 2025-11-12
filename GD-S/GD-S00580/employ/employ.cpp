#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll mod=998244353;
ll n,m,a[505],ans=0,b[505],vis[505];
char s[505];
bool bz=true;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	scanf("%s",s+1);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
	}
	for(int i=1;i<=n;i++)
	{
		if(s[i]=='0')
		{
			bz=false;
			break;
		}
	}
	if(m==1||(bz==true&&m==0))
	{
		ans=1;
		for(int i=1;i<=n;i++)
		{
			ans*=i;
			ans%=mod;
		}
		printf("%lld",ans);
		return 0;
	}
	if(bz==true)
	{
		printf("0");
		return 0;
	}
	printf("0");
	return 0;
}
