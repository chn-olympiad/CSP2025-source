#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll s[500001];
ll read(){
	char c = getchar();
	ll ans = 0;
	while (c < '0' || c > '9') c = getchar();
	while (c >= '0' && c <= '9') ans = ans * 10 + c - '0', c = getchar(); 
	return ans;
}
ll getxor(ll l, ll r){
	return s[r] ^ s[l - 1];
}
struct segment{
	ll l, r;
};
bool cmp(segment a, segment b){
	return a.r < b.r;
}
vector <segment> anss;
int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	ll n, k;
	n = read();
	k = read();
	for (ll i = 1; i <= n; i++){
		ll a;
		a = read();
		s[i] = s[i - 1] ^ a;
	}
	ll ans = 0;
	for (ll l = 0; l <= n; l++) {
		for (ll i = 1; i <= n - l; i++) {
//			cout << i << " " << i + l << " " << getxor(i, i + l) << '\n';
			if (getxor(i, i + l) == k) {
				anss.push_back({i, i + l});
			}
		}
	}
	sort(anss.begin(), anss.end(), cmp);
	ll rr = anss[0]. r;
	ans = 1;
	for (ll i = 1; i < anss.size(); i++){
		if (anss[i].l > rr){
			rr = anss[i].r;
			ans++;
		}
	}
	printf("%lld\n", ans);                  
	return 0;
}
/*
4 2
2 1 0 3

*/
