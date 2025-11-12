#include <bits/stdc++.h>
using namespace std;
int n,m,c[502];
long long ans,mod=998244353;
bool b[502];
string s;
void dfs(int t,int p)//t次序,p未录用人数 
{
	if(s[t]=='0')
	{
		p++;
	}
	if(t>=n-1)
	{
		if(n-p>=m)
		{
			ans=(ans+1)%mod;
		}
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(b[i]||c[i]<=p)continue;
		b[i]=true;
		dfs(t+1,p);
		b[i]=false;
	}
	return;
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	bool A=true;
	cin>>s;
	for(int i=0;i<s.length();i++)
	{
		if(s[i]=='0')A=false;
	}
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&c[i]);
	}
	if(A)
	{
		ans=1;
		for(int i=1;i<=n;i++)
		{
			ans=ans*i%mod;
		}
		cout<<ans;
		return 0;
	}
	for(int j=1;j<=n;j++)
	{
		b[j]=true;
		dfs(0,0);
		b[j]=false;
	}
	printf("%lld",ans);
	return 0;
}
