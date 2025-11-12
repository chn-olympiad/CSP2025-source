#include<bits/stdc++.h>
using namespace std;
bool flag[5010];
int n,a[5010];
long long ans=0;
void dfs(int k)
{
	if(k>n)
	{
		int man=0,sum=0,maxx=0;
		for (int i=1;i<=n;++i)
		{
			if(flag[i]==true)
			{
				maxx=max(maxx,a[i]);
				sum+=a[i];
				++man;
			}
		}
		if(man>=3&&sum>maxx*2) ans=(ans+1)%998244353;
		return;
	}
	flag[k]=true;dfs(k+1);
	flag[k]=false;dfs(k+1);
	return;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for (int i=1;i<=n;++i)
	  cin>>a[i];
	dfs(1);
	cout<<ans<<endl;
	return 0;
}
