#include<bits/stdc++.h>
using namespace std;
#define int long long

const int N=5005,V=5000,mod=998244353;
int n,a[N];
int res=1,dp[N],ans=1;

signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	dp[0]=1;
	for(int i=1;i<=n;i++){
		(res*=2)%=mod;
		for(int j=0;j<=a[i];j++) (ans+=dp[j])%=mod;
		for(int j=V;j>=a[i];j--) (dp[j]+=dp[j-a[i]])%=mod;
	}
	cout<<(res-ans+mod)%mod;
	return 0;
}
/*
sol：先将 $a$ 排序

然后从小到大钦定 $a_i$ 为 $\max$，然后就相当于问用 a[1,2,...,i-1] 有多少种能拼出>a_i的情况

这是个经典的背包问题。个人感觉这个可以放T3，真的好简单。
*/