#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5010,mod=998244353;
int n,a[N],mx;
ll ans;
ll dp[N<<1][2];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	mx=a[n];
	dp[0][0]=1;
	for(int i=1;i<=n;i++){
		for(int j=mx*2+1;j>=0;j--){
			int k=j+a[i];
			if(k>mx*2)k=mx*2+1;
			if(k>a[i]*2)dp[k][1]=(dp[k][1]+dp[j][0])%mod;
			dp[k][0]=(dp[k][0]+dp[j][0])%mod;
		}
	}
	for(int i=1;i<=mx*2+1;i++)ans=(ans+dp[i][1])%mod;
	cout<<ans;
	return 0;
}
