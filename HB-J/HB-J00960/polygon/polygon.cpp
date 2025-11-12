#include<bits/stdc++.h>
using namespace std;
int n,a[5005],cnt;
bool cmp(int x,int y)
{
	return x>y;
}
void dfs(int x,int y,int z)
{
	if(z>a[x])
	{
		cnt++;
		cnt%=998244353;
	}
	if(y==n-1)return;
	for(int i=y+1;i<n;i++)
	{
		dfs(x,i,z+a[i]);
	}
	return;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	sort(a,a+n,cmp);
	for(int i=0;i<n;i++)
	{
		dfs(i,i,0);
	}
	cout<<cnt;
	return 0;
}
