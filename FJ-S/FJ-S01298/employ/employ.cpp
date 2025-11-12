#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,m,c[1000],d[1000];
string s;
long long ans;
bool vis[1000]={0};
void dfs(int nday,int fail_day)
{
	if(nday!=0)
	{
		if(s[nday-1]=='0')fail_day++;
		else fail_day=0;
		for(int i=1;i<=n;i++)
			if(c[i]<=fail_day)vis[i]=1;
		if(nday==n)
		{
			ans++;
			ans%=mod;
			return;
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(vis[i])continue;
		else
		{
			vis[i]=1;
			dfs(nday+1,fail_day);
			vis[i]=0;
		}
	}
	return;
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	cin>>s;
	int count=0;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]=='1')count++;
	}
	if(count<m)
	{
		printf("0");
		return 0;
	}
	if(count==n)
	{
		ans=1;
		for(int i=n;i>=2;i--)
		{
			ans=ans*i%mod;
		}
		printf("%lld",ans);
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&c[i]);
	}
	dfs(0,0);
	
	printf("%lld",ans);
	return 0;
}

