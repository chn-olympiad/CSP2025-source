#include <bits/stdc++.h>

#define N ((int)5e5 + 10)

using namespace std;

int n, k;
int a[N], s[N];

inline bool check_case1();
inline void solve1();
inline void solve2();

int main() {
#ifdef XYX
//	freopen("xor5.in", "r", stdin);
//	freopen("xor5.out", "w", stdout);
#else 
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
#endif
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> n >> k;
	for(int i = 1;i <= n;i++) {
		cin >> a[i];
	}
	
	if(check_case1()) {
		solve1();
	}
	else {
		solve2();
	}
	
	return 0;
}

inline bool check_case1() {
	int mx = 0;
	for(int i = 1;i <= n;i++) {
		mx = max(mx, a[i]);
	}
	return mx <= 1;
}
inline void solve1() {
	if(k == 0) {
		int ans = 0;
		for(int i = 1;i <= n;i++) {
			if(a[i] == 0) ++ans;
			if(a[i] == 1 && a[i + 1] == 1) {
				++ans;
				i++;
			}
		}
		cout << ans;
	}
	else {
		int ans = 0;
		for(int i = 1;i <= n;i++) {
			if(a[i] == 1) ++ans;
		}
		cout << ans;
	}
}

bitset<N> used;
inline bool query(int l, int r) {
	for(int i = l;i <= r;i++) {
		if(used[i]) return 1;
	}
	return 0;
}
inline void update(int l, int r) {
	for(int i = l;i <= r;i++) {
		used[i] = 1;
	}
}

inline void solve2() {
	for(int i = 1;i <= n;i++) {
		s[i] = s[i - 1] ^ a[i];
	}
	
	int ans = 0, l, r;
	for(int len = 1;len <= n;len++) {
		for(int i = 1;i + len - 1 <= n;i++) {
			l = i;
			r = i + len - 1;
			
			if(query(l, r)) continue;
			
			if((s[r] ^ s[l - 1]) == k) {
				update(l, r);
				++ans;
#ifdef XYX
				cout << l << " " << r << "\n";
#endif
			}
		}
	}
	cout << ans;
}

/*
4 3
2 1 0 3
*/ 