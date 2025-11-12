#include<bits/stdc++.h>
using namespace std;
long long n,k,a,s[500001]={0},ans=0;
void dfs(long long dep,long long ans1)
{
	if(ans1>ans)
	{
		ans=ans1;
	}
	for(int i=dep;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			if((s[j]^s[i-1])==k)
			{
				dfs(j+1,ans1+1);
				return;
			}
		}
	}
	return;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(long long i=1;i<=n;i++)
	{
		cin>>a;
		s[i]=s[i-1]^a;
	}
	dfs(1,0);
	cout<<ans;
	return 0;
}
