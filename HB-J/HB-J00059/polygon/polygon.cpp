#include<bits/stdc++.h>
using namespace std;
int n,a[5005],f[5005],flag=1;
bool book[5005];
int ans;
void dfs(int x,int sum,int cnt,int s)
{
	if(book[x]==1||cnt>n)	return ;
	if(sum>s&&cnt>=3)	ans++;
	
	book[x]=1;
	for(int j=x;j<=n;j++)
		dfs(j,sum+a[j],cnt+1,max(s,a[j]));
	book[x]=0;
	return ;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]!=1)
			flag=0;
	}
	if(flag==1)
	{
		for(int i=3;i<=n;i++)
		{
			ans+=(n-i)*i+1;
		}
		cout<<(ans%998244353);
	}
	else
	{
		sort(a+1,a+n+1);
		dfs(1,a[1],1,a[1]);
		cout<<ans%998244353;
	}
	return 0;
}
