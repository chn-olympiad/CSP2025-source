#include<bits/stdc++.h>
#define max_n 5005
using namespace std;
int n;
int a[max_n];
int ans=0;
void dfs(int t,int cnt,int sum,int m,int back_n)
{
	if(cnt==m)
	{
		if(sum>a[back_n]*2)
		{
			ans++;
		}
		return;
	}
	if(t>n)
	{
		return;
	}
	for(int j=t;j<=n;j++)
	{
		dfs(j+1,cnt+1,sum+a[j],m,j);
		dfs(j+1,cnt,sum,m,t);
	}
	return;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(n<=3)
	{
		cout<<"0";
		return 0;
	}
	sort(a+1,a+1+n);
	for(int i=3;i<=n;i++)
	{
		dfs(1,0,0,i,0);
	}
	cout<<ans;
	return 0;
}
