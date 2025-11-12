#include<bits/stdc++.h>
using namespace std;
int n,m,ans;
int a[1005],b,c;
void dfs(int i,int k,int j)
{
	if(j>b) return ;
	if(k<m&&j>b) return ; 
	if(i>n)
	{
		if(k>=m) ans++;
		return ;
	}
	dfs(i+1,k,j);
	if(a[i]>k)
	{
		dfs(i+1,k+1,j+1);
	}
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		char x;
		cin>>x;
		if(x=='1') b++;
		else c++;
	 } 
	 for(int i=1;i<=n;i++) cin>>a[i];
	dfs(1,0,0);
	cout<<ans;
	return 0;
}
