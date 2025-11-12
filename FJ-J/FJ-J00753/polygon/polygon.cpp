#include<cmath>
#include<algorithm>
#include<iostream>
using namespace std;
int n,a[100005],ans=0,b[100005];
const int MOD=998244353;
dfs(int x)
{
 	if(x==1)
 	{
 		return 1;
	}
	for(int i=0;i<=1;i++)
 	{
 		dfs(x-1);
 		b[x]=i;
	}
	retrun
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
	sort(a+1,a+n+1);
	for(it i=1)
	return 0;
}
