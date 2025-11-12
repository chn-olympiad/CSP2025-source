#include<bits/stdc++.h>
using namespace std;
int const N=10005;
int n,a[N],dp[N],ans,cnt,mmax;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	ans=0;
	memset(dp,0,sizeof(dp));
	sort(a+1,a+1+n);
	if(a[1]+a[2]>a[3])
	{
		ans=1;
	}
	cout<<ans;
	return 0;
}