#include <iostream>
#include <vector>
#include <algorithm>
#define mpr make_pair
using namespace std;

const int maxn=1e5+5; 
using pii=pair<int, int>; 

vector<pii> v[maxn]; 

int f[maxn]; 
int c[maxn]; 

vector<int> C[4]; 
int cnt[4]; 

int rd() {
	int x=0, f=1;
	char c=getchar(); 
	
	while ((c < '0' || c > '9') && c != '-') {
		c=getchar(); 
	}
	if (c=='-') f=-1; 
	else {
		x = c-'0'; 
	}
	c=getchar(); 
	while (c >='0' && c <= '9') {
		x *= 10;
		x += c-'0'; 
		c = getchar(); 
	}
	return x; 
}

void solve() {
	int n, ans;
	n = rd();
	for (int i=1; i<=n; i++) {
		int a, b, z;
		a = rd(); 
		b = rd();
		z = rd(); 
		v[i].clear(); 
		
		v[i].push_back(mpr(a, 1));
		v[i].push_back(mpr(b, 2)); 
		v[i].push_back(mpr(z, 3)); 
		
		sort(v[i].begin(), v[i].end()); 
		
		f[i] = v[i][2].second;
		c[i] = v[i][2].first - v[i][1].first; 
	}
	
	C[1].clear(); 
	C[2].clear();
	C[3].clear(); 
	cnt[1] = 0;
	cnt[2] = 0;
	cnt[3] = 0; 
	ans = 0; 
	for (int i=1; i<=n; i++) {
		cnt[f[i]]++; 
		ans += v[i][2].first; 
		C[f[i]].push_back(c[i]);
	}
	sort(C[1].begin(), C[1].end()); 
	sort(C[2].begin(), C[2].end()); 
	sort(C[3].begin(), C[3].end()); 
	
	for (int i=0; cnt[1] > n/2; i++) {
		cnt[1]--; 
		ans -= C[1][i]; 
	}
	for (int i=0; cnt[2] > n/2; i++) {
		cnt[2]--; 
		ans -= C[2][i]; 
	}
	for (int i=0; cnt[3] > n/2; i++) {
		cnt[3]--; 
		ans -= C[3][i]; 
	}
	
	cout << ans << '\n'; 
}

signed main() {
	
	
	freopen("club.in", "r", stdin); 
	freopen("club.out", "w", stdout); 
	
	int t;
	t = rd(); 
	while (t--) {
		solve(); 
	}
	
	return 0; 
}
 
