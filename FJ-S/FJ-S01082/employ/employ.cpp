#include<bits/stdc++.h>
using namespace std;
int sum,m,n,a[510],c[510];
string s;
bool kg,b[510];
long long ans=1,md=998244353;
void dfs(int x)
{
	if (x==n)
	{
		int tot=0,tt=0;
		for (int i=1;i<=n;i++)
		if (c[i]<=tt||s[i-1]=='0') tt++;
		else tot++;
		if (tot>=m) ans=(ans+1)%md;
	}
	else
	{
		for (int i=1;i<=n;i++)
		{
			if (b[i]) continue;
			c[x+1]=a[i];
			b[i]=1;
			dfs(x+1);
			b[i]=0;
		}
	}
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);cin>>s;
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		if (a[i]!=0) sum++; 
	}
	for (int i=0;i<s.size();i++)
	if (s[i]=='0') kg=1;
	if (!kg)
	{
		if (sum<m) puts("0");
		else
		{
			for (long long i=1;i<=n;i++) ans=ans*i%md;
			printf("%lld",ans);
		}
		return 0;
	}
	ans=0;
	dfs(0);
	printf("%lld",ans);
}
