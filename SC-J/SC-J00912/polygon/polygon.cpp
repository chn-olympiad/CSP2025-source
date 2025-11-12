#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#define mod 998244353
typedef int ll;
using namespace std;
ll ts[5001];
ll n;
long long ans;
ll dp[5001][10001];
ll su[5001][10001];
void putin()
{
	cin>>n;
	for(ll i=0;i<n;i++) cin>>ts[i];
	sort(ts,ts+n);
}
void chuli()
{
	for(ll j=0;j<=2*ts[n-1];j++){
		for(ll i=0;i<n;i++){
			ll t=max(0,j-ts[i]);
			dp[i][j]=su[i-1][t];
			if(ts[i]>j) dp[i][j]++;
			ll f=su[i-1][j]+dp[i][j];
			f%=mod;
			su[i][j]=f;
		}
	}
	for(ll i=0;i<n;i++){
		ans+=su[i][2*ts[i]];
		ans%=mod;
	}
}
void putout(){
	cout<<ans<<endl;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	putin();
	chuli();
	putout();
	return 0;
}