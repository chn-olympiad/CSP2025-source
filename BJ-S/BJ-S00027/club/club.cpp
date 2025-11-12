#include <bits/stdc++.h>

using namespace std;

/*
char now = 'a';

// 部门
struct bumen {
	int a, b, c;
};

bool operator<(bumen a, bumen b) {
	if (now == 'a') {
		return a.a > b.a;
	} else if (now == 'b') {
		return a.b > b.b;
	} else {
		return a.c > b.c;
	}
}

multiset<bumen>::iterator max(multiset<bumen>::iterator a, multiset<bumen>::iterator b, multiset<bumen>::iterator c) {
	if (a->a > b->b) {
		if (a->a >= c->c) {
			return a;
		} else {
			return c;
		}
	} else if (a->a > c->c) {
		if (b->b > a->a) {
			return b;
		} else {
			return a;
		}
	} else if (b->b > c->c) {
		if (b->b > a->a) {
			return b;
		} else {
			return a;
		}
	} else {
		// c->c > b->c
		if (c->c > a->c) {
			return c;
		} else {
			return a;
		}
	}
}
*/

inline void read(int &x) {
	x = 0;
	int f = 1;
	char ch = getchar_unlocked();
	while (ch < '0' || ch > '9') {
		if (ch == '-') f = -1;
		ch = getchar_unlocked();
	}
	while (ch >= '0' && ch <= '9') {
		x = x * 10 + (ch - '0');
		ch = getchar_unlocked();
	}
	x *= f;
}

int main() {
	/**
	 * Made By RealDream
	 * with __CrossBow_EXE__
	 */
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t;
	read(t);
	while (t--) {
		int n, ans = 0;
		read(n);
		multiset<int, greater<int>> m;
		for (int i = 0; i < n; i++) {
			int temp;
			read(temp);
			m.insert(temp);
			read(temp);
			read(temp);
		}
		int times = 0;
		for (auto val : m) {
			++times;
			ans += val;
			if (times >= (n / 2)) break;
		}
		cout << ans << endl;
		/*
		// 新成员数量
		int n, a = 0, b = 0, c = 0;
		read(n);
		multiset<bumen> myd;
		for (int i = 0; i < n; i++) {
			read(a);
			read(b);
			read(c);
			myd.insert({a, b, c});
		}
		int ans = 0;
		a = 0, b = 0, c = 0;
		while (!myd.empty()) {
			//bumen *maxa, *maxb, *maxc;
			multiset<bumen>::iterator maxa, maxb, maxc;
			const char now_bk = now;
			bool see_a = false, see_b = false, see_c = false;
			now = 'a';
			maxa = myd.begin();
			now = 'b';
			maxb = myd.begin();
			now = 'c';
			maxc = myd.begin();
			multiset<bumen>::iterator maxn = max(maxa, maxb, maxc);
			a:
			if (maxn == maxa) {
				if (a > (n / 2)) {
					maxn = (maxb->b > maxc->c ? maxb : maxc);
					see_a = true;
				} else {
					ans += maxa->a;
					myd.erase(maxa);
				}
			}
			b:
			if (maxn == maxb) {
				if (b > (n / 2)) {
					maxn = (maxa->a > maxc->c ? maxa : maxc);
					if (maxa->a > maxc->c) {
						maxn = maxa;
						if (!see_a) goto a;
					} else {
						maxn = maxc;
					}
					see_b = true;
				} else {
					ans += maxb->b;
					myd.erase(maxb);
				}
			}
			if (maxn == maxc) {
				if (c > (n / 2)) {
					maxn = (maxa->a > maxb->b ? maxa : maxc);
					if (maxa->a > maxb->b) {
						maxn = maxa;
						if (!see_a) goto a;
					} else {
						if (!see_b) goto b;
					}
					see_c = true;
				} else {
					ans += maxc->c;
					myd.erase(*maxc);
				}
			}
			
			/*
			if (now == 'a') {
				ans += myd.begin()->a;
				++a;
				myd.erase(myd.begin());
			} else if (now == 'b') {
				ans += myd.begin()->b;
				++b;
				myd.erase(myd.begin());
			} else {
				ans += myd.begin()->c;
				++c;
				myd.erase(myd.begin());
			}
			if (a >= (n / 2)) {
				now = 'b';
			}
			* /
			cout << ans << endl;
		}
		*/
	}
	return 0;
}