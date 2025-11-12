#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=998244353;
int a[50005];
int ans=0;
int n;
void dfs(int step,int sum)
{
	if(step==n+1)
		return;
	if(a[step]<sum)
		ans++;
	dfs(step+1,sum);
	dfs(step+1,sum+a[step]);
	return;
}
signed main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	if(a[n]==1) 
	{
		ans=1;
		for(int i=1;i<=n;i++)
		{
			ans*=2;
			ans%=mod;
		}
		ans-=n;
		ans-=(n*(n-1)/2);
		cout<<ans-1;
		return 0;
	}
	else{
		dfs(1,0);
		cout<<ans<<endl;
	}
}
