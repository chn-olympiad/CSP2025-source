#include<bits/stdc++.h>
using namespace std;
int a[105],t,n,m;
bool cmp(int a,int b)
{
	return a>b;
}
void dfs(int x,int y,bool d,int k)
{
	if(a[k]==t)
	{
		cout<<y<<" "<<x;
		return ;
	}
	if(d==0)
	{
		if(x==n)
		{
			dfs(x,y+1,!d,k+1);
			return ;
		}
		dfs(x+1,y,d,k+1);
		return ;
	}	
	if(x==1)
	{
		dfs(x,y+1,!d,k+1);
		return ;
	}
	dfs(x-1,y,d,k+1);
	return ;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	t=a[1];
	sort(a+1,a+n*m+1,cmp);
	dfs(1,1,0,1);
}
