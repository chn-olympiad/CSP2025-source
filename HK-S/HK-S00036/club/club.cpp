#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back

int t, n, x, ans, sum;
vector<int> a;
vector<int> b;
vector<int> c;

void rec(int y, int ai, int bi, int ci, int s){
	int d = ai+bi+ci;
	s += y;
	if (d==n){
		ans = max(s, ans);
		return;
	}
	if (ai<n/2){
		rec(a[d], ai+1, bi, ci, s);
	}
	if (bi<n/2){
		rec(b[d], ai, bi+1, ci, s);
	}
	if (ci<n/2){
		rec(c[d], ai, bi, ci+1, s);
	}
}

signed main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	for (int k=0; k<t; k++){
		cin >> n;
		ans = 0;
		a.clear();
		b.clear();
		c.clear();
		for (int i=0; i<n; i++){
			cin >> x; a.pb(x);
			cin >> x; b.pb(x);
			cin >> x; c.pb(x);
		}
		rec(a[0], 1, 0, 0, 0);
		rec(b[0], 0, 1, 0, 0);
		rec(c[0], 0, 0, 1, 0);
		cout << ans << endl;
	}
}
