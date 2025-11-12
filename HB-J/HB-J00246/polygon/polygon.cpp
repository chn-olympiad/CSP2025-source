#include <bits/stdc++.h>
using namespace std;
int n,len[5005],ans;
void dfs(int t,int maxn,int sum)
{
	for(int i=t;i<=n;i++)
	{
		if(sum+len[i]>max(maxn,len[i])*2)
		{
			ans++;
		}
		dfs(i+1,max(len[i],maxn),sum+len[i]);
	}
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>len[i];
	}
	for(int i=1;i<=n;i++)
	{
		dfs(i+1,len[i],len[i]);
	}
	cout<<ans;
	return 0;
}
