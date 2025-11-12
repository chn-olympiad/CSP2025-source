#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
#define int long long
int n;
int a[5500];
int ans;
void dfs(int begin,int sum,int mx)
{
	if (sum>mx*2)
	{
		//cout<<sum<<' ';
		ans=(ans+1)%mod;
	}	
	for (int i=begin;i<=n;i++)
		dfs(i+1,sum+a[i],max(mx,a[i]));
}
signed main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%lld",&n);
	int mx=-1;
	for (int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		mx=max(mx,a[i]);
	}
	if (mx==1)
	{
		ans=n*(n-1)*(n-2)/6;
		ans%=mod;
		printf("%lld",ans);
		return 0;
	}
	dfs(1,0,0);
	//cout<<endl;
	printf("%lld",ans);
	return 0;
} 
/*
10:11 Finish: Maybe 64~80 pts
11:01 Check: I found a mistake! Silly me!
11:11 So,what's the color of this? Green? 
*/ 
