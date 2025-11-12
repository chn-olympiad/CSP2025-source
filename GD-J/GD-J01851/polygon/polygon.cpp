#include<bits/stdc++.h>
using namespace std;
int n;
int a[1000010];
int result;
void dfs(int x,int maxx,int p,int s)
{
	maxx=max(a[x],maxx);
	s+=a[x];
	if(p>=3&&s>2*maxx)
	{
		result++;
	}
	for(int i=x+1;i<=n;++i)
	{
		dfs(i,maxx,p+1,s);
	}
 } 
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;++i)
	{
		cin>>a[i];
	}
	dfs(0,0,1,0);
	printf("%d",result%998244353)
	return 0;
}

