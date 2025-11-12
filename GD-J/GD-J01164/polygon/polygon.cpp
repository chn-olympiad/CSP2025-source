#include <bits/stdc++.h>
using namespace std;
int n,m,a[5005];
long long ans,t,num,sum=1;
bool bo[5005];
void dfs(int sum)
{
	if(sum!=n)
	{
		bo[sum+1]=1;
		dfs(sum+1);
		bo[sum+1]=0;
		dfs(sum+1);
	}
	else
	{
		int maxn=0,num=0;
		for(int i=1;i<=n;i++)
		{
			if(bo[i])
			num+=a[i],maxn=max(maxn,a[i]);
		}
		if(num>maxn*2)
		ans=(ans+1)%998244353;
	}
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	cin>>a[i],num+=(a[i]==1);
	if(num==n)
	{
		for(int i=1;i<=n;i++)
		{
			ans+=i;
			sum=sum*2%998244353;
		}
		ans++;
		cout<<sum-ans;
	}
	else
	{
		dfs(0);
		cout<<ans;
	}
	return 0;
} 
