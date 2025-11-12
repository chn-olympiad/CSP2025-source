#include<bits/stdc++.h>
using namespace std;
const int Mod=998244353;
long long n,a[5010],ans;
void dfs(int now,int Min,int sum)
{
	if(now==n+1) return ;
	for(int i=Min;i<=n;i++)
	{
		if(now>2 && sum>a[i]) ans=(ans+1)%Mod;
		dfs(now+1,i+1,sum+a[i]);
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	long long Max=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		Max=max(Max,a[i]);
	}
	if(Max==1)
	{
		long long cnt=n*(n-1)/2%Mod;
		for(int i=2;i<n;i++)
		{
			cnt=(cnt*(n-i)/(i+1))%Mod;
			ans=(ans+cnt)%Mod;
		}
	}
	else
	{
		sort(a+1,a+n+1);
		dfs(1,1,0);
	}
	cout<<ans;
	return 0;
}
