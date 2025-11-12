#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
using ll=long long;
int a[110];
int r;
int n,m;
int sum=100;
void dfs(int x,int y,int d)
{
	while(!a[sum]) sum--;
	if(sum==r)
	{
		cout<<y<<" "<<x;
		return;
	}
	sum--;
	if(d)
	{
		if(x==n)
			dfs(x,y+1,0);
		else
			dfs(x+1,y,1);
		return;
	}
	else
	{
		if(x==1)
			dfs(x,y+1,1);
		else
			dfs(x-1,y,0);
		return;
	}
}
int main()
{ 
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			int x;
			cin>>x;
			a[x]++;
			if(i==1&&j==1) r=x; 
		}
	dfs(1,1,1);
	return 0;
}
