#include <iostream>
#include <algorithm>
#define ll long long
using namespace std;
const int N=5005,mod=998244353;
ll dp[N],suf[N];
int n,a[N];
int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	dp[0]=1;
	ll ans=0;
	for(int i=1;i<=n;i++) {
		ans=(ans+suf[a[i]+1])%mod;
		for(int j=5001+a[i];j>5001;j--)
			dp[5001]+=dp[j-a[i]];
		for(int j=5001;j>=a[i];j--)
			dp[j]=(dp[j]+dp[j-a[i]])%mod;
		for(int j=5001;j>=0;j--)
			suf[j]=(suf[j+1]+dp[j])%mod;
	}
	cout<<ans;
	return 0;
}
// T4 is an simple DP, much easier than last year's.
// Finished at 9:33 Nov.1 2025.
// Started checking!
// Played chrome://dino for a while, about 10min.
// So boring.
// Played it again qwq. The highest record is 494.
// Started checking!
// I thought I will play no more before 12:00.
// Boring!!!
// slept for 1min. 
// Checked for a while.
// At 11:01, I decided to sleep longer for afternoon.
// I still couldn't sleep because I missed her.
// At 11:07, played the dinosaur game and created a new record 1169.
// I love her.
// At 11:21, I deleted all the files named xxx.exe/in/out/ans.
// rp=inf;
