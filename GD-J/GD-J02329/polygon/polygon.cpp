#include<bits/stdc++.h> 
#define int long long
using namespace std;
const int mod=998244353;
int dp[5005][5005],a[5005],n,pw[5005];
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	pw[0]=1;
	for (int i=1;i<=n;i++){
		pw[i]=pw[i-1]*2%mod;
	}
	for (int i=1;i<=n;i++){
		cin>>a[i];	
	}
	sort(a+1,a+n+1);
	dp[0][0]=1;
	for (int i=1;i<=n;i++){
		for (int j=0;j<=a[n];j++){
			dp[i][j]=dp[i-1][j];
			if (j>=a[i]){
				dp[i][j]=(dp[i][j]+dp[i-1][j-a[i]])%mod;
			}
		}
	}
	int ans=0;
	for (int i=3;i<=n;i++){
		int ct=pw[i-1];
		for (int j=0;j<=a[i];j++){
			ct=(ct-dp[i-1][j]+mod)%mod;
//			cout<<dp[i-1][j]<<" ";
		}
//		cout<<endl;
		ans=(ans+ct)%mod;
	}
	cout<<ans;
	return 0;
}
/*
9:07
pass all examples

I will sit here for 3h.
Maybe I will AFO in the afternoon.
I think my classmates will win,but I find out that I as vegetable as one year ago.
wsy can solve AGC *3000 problems,he can study for more than 12h in one day and dont play games at all.
cyq's rating is *4091,higher than tourist and jiangly,her also have 10^1000 dollars.
and xza is very good in whk,it's easy for him to get to THU.
Can I go to PKUWC or NOIWC?It sounds impossible.
It very unfair that many people is rich or smart.
But what can I say?I can just shouzhe. 
*/ 
