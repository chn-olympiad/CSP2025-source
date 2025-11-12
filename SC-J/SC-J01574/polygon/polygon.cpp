#include<bits/stdc++.h>
using namespace std;
long long n,a[100005],sum;
bool vis[100005];
void dfs(int step)
{
	if(step>n)
	{
		long long num=0,s=0,maxn=0;
		
		for(int i=1;i<=n;i++)
		{
			if(vis[i]==1)
			{
				num++;
				s+=a[i];
				maxn=max(maxn,a[i]);	
			}
		}
		if(num<3||s<=maxn*2)return;
		sum++;
		sum%=998244353;
		return;
	}
	vis[step]=1;
	dfs(step+1);
	vis[step]=0;
	dfs(step+1);
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
	dfs(1);
	cout<<sum;
	return 0;
}