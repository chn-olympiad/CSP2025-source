#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int maxn = 555;

const ll mod = 998244353;
inline ll f(ll x) {
	ll ans = 1;
	for(ll i = 2; i<=x; ++i)ans = (ans * i) % mod;
	return ans;
}
//inline ll qpow(ll a,ll b) {
//	ll ans(1);
//	while(b) {
//		if(b&1)ans = (ans * a) % mod;
//		a = (a*a) % mod;
//		b>>=1;
//	}
//	return ans;
//}
//inline ll inv(ll x) {
//	return qpow(x,mod-2);
//}
void solve();
int main() {
//	freopen("employ.in","r",stdin);
//	freopen("employ.out","w",stdout);
	solve();
	return 0;
}
bool s[maxn];
int pre[maxn];
char x;
ll a[maxn];
int cnt2=0;
int n,m,cnt(0);
bool vis[maxn];
ll ans;
void dfs(int cur = 1,int die = 0) {
	if(cur > n) {
		if(n >= (m+die))
			++ ans;
//		while(ans >= mod)ans-=mod;
		return;
	}
	int non = n - cur + 1;
	if( ((cur - die - 1) >= m)  ) {//|| ((pre[cur-1] == pre[n]) && non >= cnt2)
		ans += f(non);
		ans %= mod;
		return ;
	}
	for(int i = 1; i<=n; ++i)if(!vis[i]) {
			vis[i]=true;
			if((die<a[i]) && s[i])dfs(cur + 1,die);
			else dfs(cur+1,die+1);
			vis[i]=false;
		}
}
void solve() {
	scanf("%d%d",&n,&m);
	for(int i = 1; i<=n; ++i) {
		cin>>x;
		s[i]=x^48;
		if(s[i])++cnt;
		pre[i] = pre[i-1];
		if(!s[i])++pre[i];
	}
	for(int i = 1; i<=n; ++i) {
		cin>>a[i];
		if(a[i]==0)++cnt2;
	}
	ans = 0;
	sort(a+1,a+n+1);
	reverse(a+1,a+n+1);
	if(n == m) {
		if(cnt != n) {
			cout<<0;
			return;
		}
		if(cnt2!=0) {
			cout<<0;
			return;
		}
		cout<<f(n);
		return;
	}
	dfs();
	cout<<ans;
}
/*
3 2 101 1 1 2

10 5
1101111011
6 0 4 2 1 2 5 4 3 3
*/
