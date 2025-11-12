#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,a[5007];
const ll mod=998244353;
ll dp[5007],ex,ans;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	dp[0]=1;
	for(int i=1;i<=n;i++){
		ans=(ans+ex)%mod;
		ex=(ex*2)%mod;
		for(int j=5001;j>=0;j--){
			if(j>a[i]) ans=(ans+dp[j])%mod;
			if(j+a[i]>5001) ex=(dp[j]+ex)%mod;
			else dp[j+a[i]]=(dp[j]+dp[j+a[i]])%mod;
		}
	}
	cout<<ans;
	return 0;
} 
