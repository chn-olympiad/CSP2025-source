#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=5e3+6,md=998244353;
ll dp[2][N];
ll a[N];
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	ll n,l=5000;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+1+n);
	ll ans=0,sum=0;
	dp[0][0]=1;
	for(int i=1;i<=n;i++){
		(ans+=sum)%=md;
		for(int j=l;j>a[i];j--)
			(ans+=dp[(i-1)%2][j])%=md;
		(sum*=2)%=md;
		for(int j=0;j<=l;j++)
			dp[i%2][j]=dp[(i-1)%2][j];
		for(int j=0;j<=l;j++){
			if(j+a[i]>l)
				(sum+=dp[(i-1)%2][j])%=md;
			else
				(dp[i%2][j+a[i]]+=dp[(i-1)%2][j])%=md;
		}
	}
	cout<<ans;
	return 0;
}