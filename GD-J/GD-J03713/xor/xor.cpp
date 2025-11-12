#include<bits/stdc++.h>
using namespace std;
const int N=5e5;
int n,k;
int a[N+23];
int dp[N+23];
int ans;
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)	cin>>a[i];
	for(int i=1;i<=n;i++)	dp[i]=dp[i-1]^a[i];
	int l=-1;
	for(int i=1;i<=n;i++){
		for(int j=l;j<i;j++){
			if((dp[j]^dp[i])==k){
				ans++;
				//cout<<j+1<<' '<<i<<endl;
				//cout<<dp[j]<<' '<<dp[i]<<' '<<(dp[i]^dp[j])<<" "<<endl;
				l=i;
				break;
			}
		}
	}
	cout<<ans;
	return 0;
}
