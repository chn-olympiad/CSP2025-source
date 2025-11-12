#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define for1(i,a,b) for(ll i=a;i<=b;++i)
#define for0(i,a,b) for(ll i=a;i>=b;--i)
const ll N = 1e4+20, M = 2e6+10;
const ll MOD = 0;
ll n, m, k, ans = 1e18, top;
ll c[7][1000010], f[N];
ll F (ll now) {return f[now] == now ? now : f[now] = F (f[now]);}
struct st{
	int u, v;
	ll f;
	bool operator < (st tmp) const {
		return f < tmp.f;
	}
}lc[M];
struct node{
	int u, v;
	ll f;
	bool operator < (node temp) const {
		return f < temp.f;
	}
}l[M];
void check (ll z){
	top = 0;
	for1 (i, 1, n){
		lc[++ top] = {l[i].u, l[i].v, l[i].f};
	}
	ll sum = 0;
	ll cnt = 0, h = 0;
	for1 (i, 1, k){
		if (z&(1 << (i-1))){
			++ sum;
			h += c[i][0];
			for1 (j, 1, n){
				lc[++ top] = {n+i, j, c[i][j]};
			}
		}
	}
	sort (lc+1, lc+top+1);
	for1 (i, 1, n+k)	f[i] = i;
	for1 (i, 1, top){
		ll fu = F ((ll) lc[i].u), fv = F ((ll) lc[i].v);
		if (fu == fv)	continue;
		f[fu] = fv; h += lc[i].f;
		if (++ cnt >= sum+n-1){
			ans = min (ans, h);
		}
	}
}
signed main (){
  freopen ("road.in", "r", stdin);
  freopen ("road.out", "w", stdout);
	ios::sync_with_stdio (0);
	cin.tie (0), cout.tie (0);
	cin >>n >>m >>k;
	if (m > 1e5 or k > 5){
		cout <<0;
		return 0;
	}
	for1 (i, 1, m){
		cin >>l[i].u >>l[i].v >>l[i].f;
	}
	sort (l+1, l+m+1);
	for1 (i, 1, k){
		cin >>c[i][0];
		for1 (j, 1, n){
			cin >>c[i][j];
		}
	}
	for1 (i, 0, (1 << k)-1){
		check (i);
	}
	cout <<ans;
	return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/
// 52 pts
