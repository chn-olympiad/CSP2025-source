#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=5005,M=998244353;
ll js,dp[N],maxx,a[N],n;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n;dp[0]=1;
	for(ll i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+1+n);
	for(ll i=1;i<=n;i++)
	{
		for(ll j=maxx;j>a[i];j--)js=(js+dp[j])%M;
		for(ll j=min((ll)5001,maxx+a[i]);j>=a[i];j--){
			if(j==5001)
			{
				ll sum=0;
				for(ll u=5001;u>5001-a[i];u--)
					sum+=dp[u],sum%=M;
				dp[j]=(dp[j]+sum)%M;
			}
			dp[j]=(dp[j]+dp[j-a[i]])%M;
		}
		maxx=min(maxx+a[i],(ll)5001);
//		for(int i=maxx;i>=0;i--)
	}
	cout<<js;
	return 0;
}