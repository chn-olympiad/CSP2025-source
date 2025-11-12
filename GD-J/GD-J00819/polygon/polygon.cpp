#include <bits/stdc++.h>
using namespace std;
const int MOD=998244353;
const int MAXS=5000;
/*
please let me get 50+pts!!!!
*/
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;i++){
    	cin>>a[i];
	}
    sort(a.begin(),a.end());
    vector<int >pow2(n+1);
    pow2[0]=1;
    for(int i=1;i<=n;i++){
    	pow2[i]=(pow2[i-1]*2)%MOD;
	}
	vector<int>dp(MAXS+1,0);
	dp[0]=1;
	int ans=0;
	for(int i=0;i<n;i++){
		int tot=pow2[i];
		int los=0;
		for(int j=0;j<=a[i]&&j<=MAXS;j++){
			los=(los+dp[j])%MOD;
		}
		ans=(ans+(tot-los)%MOD)%MOD;
		for(int j=MAXS;j>=a[i];j--){
			dp[j]=(dp[j]+dp[j-a[i]])%MOD;
		}
	}
	ans=(ans%MOD+MOD)%MOD;
	cout<<ans;
    return 0;
}
//#Shang4Shan3Ruo6Shui4
