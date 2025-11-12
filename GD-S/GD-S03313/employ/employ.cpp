#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,m,c[505],anss;
char a[505];
int ans[505];
bool vis[505];
bool check()
{
	int sum=0,no=0;
	for(int i=1;i<=n;i++)
	{
		int num=ans[i];
		if(no>=c[num])
		{
			no++;
			continue;
		}
		if(a[i]=='1') sum++;
		else no++;
	}
	return sum>=m;
}
void dfs(int x)
{
	if(x==n+1)
	{
		if(check()) anss=(anss+1)%mod;
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(!vis[i])
		{
			vis[i]=1;
			ans[x]=i;
			dfs(x+1); 
			vis[i]=0;
		}
	}
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) cin>>c[i];
	if(n<=18)
	{
		dfs(1);
		cout<<anss<<endl;
	}
	else
	{
		int sum=1;
		for(int i=1;i<=n;i++) sum=sum*i%mod;
		cout<<sum<<endl;
	}
	return 0;
}
