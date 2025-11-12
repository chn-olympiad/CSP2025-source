#include<bits/stdc++.h>
using namespace std;
int n=0,a[1145140],b[1145140],p=0,cnt=0;
void dfs(int x,int y,int z,int cntt)
{
	if(b[z]!=0)
	{
		return ;
	}
	if(a[z]>x)
	{
		x=a[z];
	}	
	y=y+a[z];
	if(cntt>=3&&y>x*2)
	{
		cnt++;
	}
	for(int i=z+1;i<=n;i++)
	{
		dfs(x,y,i,cntt+1);
	}
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
	}
	dfs(0,0,0,0);
	cout<<cnt%998244353;
	return 0;
}
