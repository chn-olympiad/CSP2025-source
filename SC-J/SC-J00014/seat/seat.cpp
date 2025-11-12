#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define res(i,a,n) for(ll i = a; i <= n; i++)
const int N = 1e5+5;
ll n, m, a[N], x, r;
bool cmp(ll x, ll y) {
	return x > y;
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
    cin >> n >> m;
    res(i, 1, n*m) cin >> a[i];
    r = a[1];  
    sort(a+1, a+1+n*m);
    ll k = n*m+1 - (lower_bound(a+1, a+n*m+1, r) - a);
    if(k % n) x = k/n+1;
    else x = k/n;
    if(x % 2) cout << x << ' ' << (k%n == 0 ? n : k%n);
	else cout << x << ' ' << n-(k%n == 0 ? n : k%n)+1;
	return 0;
}