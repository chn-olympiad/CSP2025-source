#include <bits/stdc++.h>
using namespace std;
const int b=998244353;
int a[5001];
int n;
long long dfs(int maxn,int x,int sum,int cnt)
{
	if(x==n)
	{
		if(sum>(2*maxn)&&cnt>=3)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	else
	{
		return (dfs(a[x],x+1,sum+a[x],cnt+1)+dfs(maxn,x+1,sum,cnt)+b)%b;
	}
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
	cout<<dfs(0,1,0,0);//(int maxn,int x,int sum,int cnt)
	return 0;
}
