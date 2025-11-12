#include <bits/stdc++.h>
using namespace std;
long long n,a[50005];
long long all,maxn,minn,cnt=0,ans;
/*
 * 1 2 3 4 5
 * 1 2 3  6 3
 * 1 2 4  7 4
 * 1 2 5  8 5
 * 1 3 4  8 4
 * 1 3 5  9 5
 * 1 4 5  10 5
 * 2 3 4  9 4
 * 2 3 5  10 5
 * 2 4 5  11 5
 * 3 4 5  12 5
 * 1 2 3 4  10 4
 * 1 3 4 5  13 5
 * 2 3 4 5  14 5
 * 1 2 3 4 5  15 5
*/
void dfs(int sum,int t)
{
	all+=a[t];
	minn=min(maxn,a[t]);
	maxn=max(maxn,a[t]);
	cnt++;
	
	if(cnt==sum)
	{
		if(all>maxn*2)
		{
			ans++;
		}
		all-=a[t];
		if(maxn==a[t]) maxn=minn;
		cnt--;
		return;
	}
	for(int j=t;j<n;j++)
	{
		dfs(sum,j+1);
	}
	all-=a[t];
	if(maxn==a[t]) maxn=minn;
	cnt--;
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
	for(int i=3;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			dfs(i,j);
		}
	}
	cout<<ans;
	return 0;
}
