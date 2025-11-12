#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll N = 5e3 + 7, MOD = 998244353;
ll n, i, a, s, j, x, ans, suma, maxa;
ll A[N], dp[N/5][N/7], c[N*2][N];
ll solve2(){
	dp[0][0]=1;
	for(i=1;i<=n;i++){
		a=A[i];
		for(s=min(maxa*2+1,suma-a);s>=0;s--){
			for(j=a;j>=0;j--)dp[min(maxa*2+1,s+a)][a]+=dp[s][j], dp[min(maxa*2+1,s+a)][a]%=MOD;
		}
	}
	for(s=0;s<=min(maxa*2+1,suma);s++)for(j=0;j<=maxa;j++){
		ans+=dp[s][j]*(s>j*2), ans%=MOD;
	}
	return ans;
}
void dpadd(ll x, ll y, ll w0){
	for(++y;y<=maxa+1;y+=(y&-y))c[x][y]+=w0, c[x][y]%=MOD;
}
ll dps(ll x, ll y){
	ll ans = 0; for(++y;y;y-=(y&-y))ans+=c[x][y], ans%=MOD; return ans;
}
ll solve3(){
	dpadd(0, 0, 1);
	for(i=1;i<=n;i++){
		a=A[i];
		for(s=min(maxa*2+1,suma-a);s>=0;s--){
			dpadd(min(maxa*2+1,s+a), a, dps(s, a));
		}
	}
	for(s=2;s<=min(maxa*2+1,suma);s++){
		ans = (ans + dps(s, (s+1)/2-1)) % MOD;
	}
	return ans;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(i=1;i<=n;i++){
		cin>>A[i];
		suma += A[i];
		maxa = max(maxa, A[i]);
	}
	sort(A+1, A+n+1);
	if(A[n]==1){
		for(x=1,i=n;i;i--)x=x*2%MOD;
		cout<<(x+MOD-1-n-n*(n-1)/2)%MOD;
		return 0;
	}
	if(n<=500){
		cout<<solve2(); return 0;
	}
	cout<<solve3(); return 0;
}
