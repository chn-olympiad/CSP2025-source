/*
Hello, SB! ccf!
Why I finished t1-3 on 9:15?
HOW MUCH WATER IN YOUR PROBLEMS AND IN YOUR BRAIN?
And why you can get so much money by these GESP lv.1 problems?
DO YOU HAVE A HEART?
*/
#include<bits/stdc++.h>
#define rep(i,s1,s2,s3) for(i = s1;i <= s2 ;i += s3)
#define r(i,s1,s2,s3) for(i = s1;i >= s2 ;i -= s3)
#define INF 0x7f7f7f7f
#define ll long long
using namespace std;
const ll mod = 998244353;
ll n,m,sum,ans,a[5010],dp[5000010];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	ll i,j;
	rep(i,1,n,1) cin>>a[i];
	sort(a + 1,a + 1 + n);
	dp[0] = 1;
	rep(i,1,n,1){
		m += a[i];
		r(j,m,a[i],1){
			if(j <= m - a[i] && j > a[i]) ans = (ans + dp[j]) % mod;
			dp[j] = (dp[j] + dp[j - a[i]]) % mod;
		}
	}
	cout<<ans;
	return 0;
}
