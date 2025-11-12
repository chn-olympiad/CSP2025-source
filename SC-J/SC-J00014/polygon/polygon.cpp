#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define res(i,a,n) for(ll i = a; i <= n; i++)
const int N = 1e5+5;
const ll mod = 998244353;
ll n, a[N], ans; 
void solve1(ll now, ll sum, ll maxn) {
	if(now > n) {
		if(sum > maxn*2) ans = (ans+1) % mod;
		return ;
	}
	solve1(now+1, sum+a[now], max(maxn, a[now]));
	solve1(now+1, sum, maxn);
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
    cin >> n;
    res(i, 1, n) cin >> a[i];
    sort(a+1, a+1+n);
    if(a[n] == 1) cout << n*(n-1)*(n-2)/6;
	else {
		if(n <= 20) {
			solve1(1, 0, 0);
			cout << ans;
		}		
	} 
	return 0;
}
