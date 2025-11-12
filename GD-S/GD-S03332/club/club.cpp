#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// why do you doit to me
// i dont know dynamic programminnnnnnnnnng

/*
1
4
1 1 9
2 5 9
3 3 9
3 9 9
wrong
*/

struct Member {
	int a, b, c;
	int diff, sum;
};

bool cmp(Member x, Member y) {
//	return x.diff + x.sum < y.diff + y.sum;
	if (x.diff != y.diff) return x.diff > y.diff;
	return x.sum > y.sum;
}

int main() {
	
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);

	cout.tie(0);
	
	int t;
	cin >> t;
	while (t--) {
		int n, a=0, b=0, c=0, ans=0;
		cin >> n;
		int l=n>>1;
		vector<Member> m(n);
		for (int i=0;i<n;++i) {
			cin >> m[i].a >> m[i].b >> m[i].c;
			m[i].diff = abs(m[i].a - m[i].b) + abs(m[i].a - m[i].c) + abs(m[i].b - m[i].c);
			m[i].sum = m[i].a + m[i].b + m[i].c;
		}
		sort(m.begin(), m.end(), cmp);
		for (int i=0;i<n;++i) {
			int aa = m[i].a, bb = m[i].b, cc = m[i].c;
//			cout << aa << ' ' << bb << ' ' << cc << ' ' << '\n';
//			cout << a << ' ' << b << ' ' << c << ' ' << ans << ' '<< "WHYYYY???\n";
			// three same
			if (aa == bb && bb == cc) {
				if (a < l) a++, ans += aa;
				if (b < l) b++, ans += bb;
				else c++, ans += cc;
				continue;
			} 
			// one greatest
			else if (a < l && aa > bb && aa > cc) {
				a++, ans += aa;
			} else if (aa > bb && aa > cc && bb > cc && b < l) {
				b++, ans += bb;
			} else if (aa > bb && aa > cc && cc > bb && c < l) {
				c++, ans += cc;
			} else if (b < l && bb > aa && bb > cc) {
				b++, ans += bb;
			} else if (bb > aa && bb > cc && aa > cc && a < l) {
				a++, ans += a;
			} else if (bb > aa && bb > cc && cc > aa && c < l) {
				c++, ans += cc;
			} else if (c < l && cc > aa && cc > bb) {
				c++, ans += cc;
			} else if (cc > aa && cc > cc && aa > bb && a < l) {
				a++, ans += a;
			} else if (cc > aa && cc > cc && bb > aa && b < l) {
				b++, ans += bb;
			}
			// two same
			else if (a < l && aa == bb) {
				a++, ans += aa;
			} else if (b < l && aa == bb) {
				b++, ans += bb;
			} else if (a < l && aa == cc) {
				a++, ans += aa;
			} else if (c < l && aa == cc) {
				c++, ans += cc;
			} else if (b < l && bb == cc) {
				b++, ans += bb;
			} else if (c < l && bb == cc) {
				c++, ans += cc;
			} 
			else {
				if (a < l) {
					a++, ans += aa;
				} else if (b < l) {
					b++, ans += bb;
				} else if (c < l) {
					c++, ans += cc;
				}
				else cout << aa << ' ' << bb << ' ' << cc << " ???\n";
			}
		}
		cout << ans << '\n';
		
	}	
	return 0;
}
