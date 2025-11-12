#include<bits/stdc++.h>
using namespace std;
int n;
int a[5005];
long long cnt=0;
void dfs(int sum,int mx,int x,int s)
{
	if(sum-mx>mx&&s>=3)
	{
		cnt++;
		cnt=cnt%998224353;
	}
	for(int i=x;i<=n;i++)
	{
		dfs(sum+a[i],max(mx,a[i]),i+1,s+1);
	}
	return ;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(n==3)
	{
		if(a[1]+a[2]>a[3])
		{
			cout<<1;
		}
		else cout<<0;
		return 0;
	}
	dfs(0,0,0,0);
	cout<<cnt/2;
}
