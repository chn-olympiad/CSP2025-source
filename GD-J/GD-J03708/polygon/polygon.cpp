#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
long long n,a[5009],dp[5009],ans;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		if(i>=3){
			ans+=dp[a[i]];
			ans%=mod;
		}
		for(int j=5001;j>=0;j--){
			if(a[i]>j)dp[j]+=dp[0]+1;
			else dp[j]+=dp[j-a[i]];
			dp[j]%=mod;
		}
	}
	cout<<ans<<endl;
	return 0;
}
//芜湖，我觉得可以AK了，虽然是J，但也可以了 
