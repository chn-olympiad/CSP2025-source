#include<bits/stdc++.h>
using namespace std;
long long n,m,c[550],ans=0,p=998244353;
string s;
bool Z=1,bj[550];
void dfs(long long q,long long cnt)
{
	if(n-q<m)return;
	if(cnt==n&&n-q>=m)
	{
		ans++;
		if(ans>=p)ans-=p; 
//		printf("ans++\n");
	}
	if(cnt==n)return; 
	for(long long i=1;i<=n;i++)
	{
		if(bj[i])continue;
		if(s[cnt]==48)
		{
			bj[i]=1;
//		printf("{%lld %lld %lld\n",i,q+1,cnt+1);
			dfs(q+1,cnt+1);
//			printf("    }\n");
			bj[i]=0;
			continue;
		}
		if(c[i]<=q)
		{
			bj[i]=1;
//		printf("{%lld %lld %lld\n",i,q+1,cnt+1);
			dfs(q+1,cnt+1);
//			printf("    }\n");
			bj[i]=0;
			continue;
		}
		bj[i]=1;
//		printf("{%lld %lld %lld\n",i,q,cnt+1);
		dfs(q,cnt+1);
//		printf("     }\n");
		bj[i]=0;
	}
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(long long i=1;i<=n;i++)
	{
		cin>>c[i];
		if(c[i]==0)Z=0;
	}
	for(long long i=0;i<n;i++)
	{
		if(s[i]-48==0)Z=0;
	}
	if(n==m)
	{
		if(Z)
		{
			cout<<0;
			return 0;
		}
		for(long long i=1;i<=n;i++)
		{
			ans=ans*i;
			ans%=p;
		}
		cout<<ans;
	}
	else
	{
		dfs(0,0);
		cout<<ans;
	}
	return 0;
}
