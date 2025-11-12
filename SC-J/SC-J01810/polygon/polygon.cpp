#include<bits/stdc++.h>
#define N 5010
#define p 998244353
using namespace std;
int dp[N],a[N],n,mx,sum,pw;
int main(){
	freopen("polygon.in","r",stdin),freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0);
	cin>>n; for(int i=1;i<=n;i++) cin>>a[i],mx=max(mx,a[i]);
	sort(a+1,a+n+1),dp[0]=1; for(int i=1;i<=n;i++){
		for(int j=0;j<=a[i];j++) sum=(sum+dp[j])%p;
		for(int j=mx;j>=a[i];j--) dp[j]=(dp[j]+dp[j-a[i]])%p;
	}
	pw=1; for(int i=1;i<=n;i++) pw=pw*2%p; pw=(pw-1+p)%p;
	return cout<<(pw-sum+p)%p<<endl,0;
}