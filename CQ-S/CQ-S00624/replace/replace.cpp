#include <bits/stdc++.h>
const int N = 2e5 + 5; 
using namespace std; 
int n, q, ans; 
struct Node {
	int ln, lln, L, R, RR; 
	string s, t; 
} a[N];
inline void work(int i) {
	a[i].ln = a[i].s.size(); 
	int L = 0, R = a[i].ln - 1; 
	while(L <= R) {
		if(a[i].s[L] == a[i].t[L]) ++L; 
		else break; 
	}
	while(R >= L) {
		if(a[i].s[R] == a[i].t[R]) --R; 
		else break; 
	}
	a[i].L = L; a[i].R = R; a[i].lln = R - L + 1; 
	a[i].RR = a[i].ln - 1 - a[i].R; 
	return ; 
}
inline bool pd(int x, int y) {
	if(a[x].L > a[y].L) return 0; 
	if(a[x].RR > a[y].RR) return 0; 
	int ll = a[y].L - a[x].L, rr = a[y].R + a[x].RR; 
	for(int i = ll; i <= rr; ++i)
		if(a[x].s[i - ll] != a[y].s[i] || a[x].t[i - ll] != a[y].t[i]) return 0; 
	return 1; 
}
inline void solve() {
	cin >> n >> q; 
	for(int i = 1; i <= n; ++i) cin >> a[i].s >> a[i].t, work(i); 
	while(q--) {
		cin >> a[0].s >> a[0].t; 
		work(0); ans = 0; 
		for(int i = 1; i <= n; ++i) 
			if(a[i].lln == a[0].lln && pd(i, 0)) ++ans; 
		cout << ans << "\n"; 
	}
	return ; 
}
int main() {
	freopen("replace.in", "r", stdin); 
	freopen("replace.out", "w", stdout); 
	ios::sync_with_stdio(false); 
	cin.tie(0); cout.tie(0); 
	solve(); 
	return 0; 
}
