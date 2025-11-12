#include<bits/stdc++.h>
using namespace std;
int n,a[10000005],s;
void dfs(int t,int deep,int ii,int maxx)
{
	if(deep>n)
	{
		return;
	}
	if(maxx*2<t&&maxx>0)
	{
		if(deep>2)
		{
			s++;
		}
	}
	for(int i=ii+1;i<n;i++)
	{
		dfs(t+a[i],deep+1,i,max(maxx,a[i]));
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
	for(int i=0;i<n;i++)
	{
		dfs(a[i],1,i,a[i]);
	}
	cout<<s;
	return 0;
 } 
