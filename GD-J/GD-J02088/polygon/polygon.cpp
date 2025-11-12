#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,c;
int a[50005];
void dfs(int k,int d,int z,int cd,int kt)
{
	if(cd>=3)
	{
		if(z>d*2)
		{
			c++;
			c%=mod;	
		} 
	}
	if(kt+cd-1>=n) 
	return ;
	for(int i=k+1;i<=n;i++)
	{
		dfs(i,max(a[i],d),z+a[i],cd+1,kt); 
	} 
}
signed main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout); 
	cin>>n;
	for(int i=1;i<=n;i++)
	cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		dfs(i,a[i],a[i],1,i);
	}
	cout<<c<<'\n'; 
	return 0;
} 
