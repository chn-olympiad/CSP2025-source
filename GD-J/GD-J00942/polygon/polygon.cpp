#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e3+100,mod=998244353;
int n;
ll V;
ll a[N],dp[N],p[N],s[N];
void add(ll &x,ll y){
	x=(x+y)%mod;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i],V=max(V,a[i]);
	V++;
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		dp[i]=dp[i-1];
		ll sum=0;
		for(int j=a[i]+1;j<=V;j++)
			add(sum,p[j]-s[j]+mod);
		add(dp[i],sum);
		for(int j=V;j>=0;j--)
			add(p[min(V,j+a[i])],p[j]);
		add(p[a[i]],1);
		add(s[a[i]],1);
	}
	cout<<dp[n];
	return 0;
}
/*
10
1 1 1 1 1 1 1 1 1 1
968

*/
