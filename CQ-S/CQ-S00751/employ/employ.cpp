#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
long long n,m,a[1000010],c[1000010],vis[1000010],ans,fl=1;
char ch[1000010];
void dfs(long long k)
{
	if(k==n+1)
	{
		long long gu=0;
		for(int i=1;i<=n;i++)
		{
			if(ch[i]=='0'||gu>=c[a[i]])
			{
				gu++;
			}
		}
		if(n-gu>=m)
		{
//			for(int i=1;i<=n;i++)
//			{
//				cout<<a[i]<<' ';
//			}cout<<'\n';
			ans++;
		}
		return ;
	}
	for(int i=1;i<=n;i++)
	{
		if(!vis[i])
		{
			vis[i]=1;
			a[k]=i;
			dfs(k+1);
			vis[i]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>ch[i];
		if(ch[i]!='1') fl=0;
	}
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
	}
	if(n<=10&&m<=10)
	{
		dfs(1);
		cout<<ans;
	}
	else if(fl)
	{
		long long sum=0;
		for(int i=1;i<=n;i++)
		{
			sum+=(c[i]!=0);
		}
		if(sum<m)
		{
			cout<<0;
		}
		else
		{
			ans=1;
			for(int i=1;i<=n;i++)
			{
				ans=(ans*i)%mod;
			}
			cout<<ans;
		}
	}
	return 0;
}
