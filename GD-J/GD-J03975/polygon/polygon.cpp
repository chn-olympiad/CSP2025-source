#include <iostream>
#include <algorithm>
using namespace std;
using ll=long long;
ll n,a[5005],dp[5005][5005],ans,mod=998244353;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0); 
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		for(int k=0;k<=5001;k++){
			if(k<a[i]){
				dp[i][k]=dp[i-1][0]+dp[i-1][k]+1LL;
			}
			else{
				dp[i][k]=dp[i-1][k-a[i]]+dp[i-1][k];
			}
			dp[i][k]%=mod;
		}
		ans+=dp[i-1][a[i]];
		ans%=mod;
	}
	cout<<ans<<endl;
	return 0;
}
