#include <bits/stdc++.h>
const int N = 1e5 + 5; 
using namespace std; 
int n, cnt[4], ans; 
vector<int> vc; 
struct Node {
	int a, b, c; 
	int mx, cz, id; 
} a[N];
inline int db(int x) {
	if(a[x].mx == a[x].a) return 1; 
	if(a[x].mx == a[x].b) return 2; 
	return 3; 
}
inline int db2(int x) {
	if(a[x].id == 1) return a[x].mx - max(a[x].b, a[x].c); 
	if(a[x].id == 2) return a[x].mx - max(a[x].a, a[x].c); 
	return a[x].mx - max(a[x].a, a[x].b); 
}
inline void solve() {
	cin >> n; cnt[3] = cnt[1] = cnt[2] = ans = 0; vc.clear(); 
	for(int i = 1; i <= n; ++i) {
		cin >> a[i].a >> a[i].b >> a[i].c; 
		a[i].mx = max(a[i].a, max(a[i].b, a[i].c)); ans += a[i].mx; 
		a[i].id = db(i); ++cnt[a[i].id]; 
		a[i].cz = db2(i); 
	}
//	cout << ans << "    "; for(int i = 1; i <= n; ++i) cout << a[i].cz << " "; cout << "\n"; 
	int flag = 0; 
	if(cnt[1] > n / 2) flag = 1; 
	if(cnt[2] > n / 2) flag = 2; 
	if(cnt[3] > n / 2) flag = 3; 
//	cout << "flag " << flag << "\n"; 
	if(!flag) return cout << ans << "\n", void(); 
	for(int i = 1; i <= n; ++i)
		if(a[i].id == flag) vc.push_back(a[i].cz); 
	sort(vc.begin(), vc.end()); 
	int js = cnt[flag] - (n / 2); 
//	cout << "js " << js << "\n"; 
	for(int i = 0; i < js; ++i) ans -= vc[i]; 
	cout << ans << "\n"; 
	return ; 
}
int main() {
	freopen("club.in", "r", stdin); 
	freopen("club.out", "w", stdout); 
	ios::sync_with_stdio(false); 
	cin.tie(0); cout.tie(0); 
	int _; cin >> _; 
	while(_--) solve(); 
	return 0; 
}
