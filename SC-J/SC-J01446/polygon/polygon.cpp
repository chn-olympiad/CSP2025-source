#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
long long ans=0;
int a[5005];
int n;
void dfs(int k,long long sum,int x,int step)
{
	if(step>k)
	{
		if(sum>2*a[x])
		{
			ans++;
			ans=ans%mod;
		}
		return;
	}
	for(int i=x+1;i<=n;i++)
	{
		dfs(k,sum+a[i],i,step+1);
	}
} 
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	stable_sort(a+1,a+1+n);
	for(int i=3;i<=n;i++)
	{
		dfs(i,0,0,1); 
	}
	cout<<ans%mod; 
	return 0;
}