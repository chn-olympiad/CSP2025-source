#include <bits/stdc++.h>
using namespace std;

#define LOCAL
//#define DEBUG

typedef long long int ll;
typedef pair<int, int> PII;

const int N = 1e5 + 10, M = 2e5 + 10, INF = 0x3f3f3f3f, mod = 1e9 + 7;
int n, m, k, cnt, ans;

struct node {
	int a, b, c;
	node() {}
	node(int _a, int _b, int _c) {
		a = _a;
		b = _b;
		c = _c;
	}
};

struct node2 {
	int d2, to2;
	node2() {}
	node2(int _d2, int _to2) {
		d2 = _d2;
		to2 = _to2;
	}
};
#if defined(__unix__) || defined(__linux__)
#define getchar getchar_unlocked
#else
#define getchar _getchar_nolock
#endif

namespace IO_fast_int32 {
	inline void read(int& x) {
		x = 0;
		int f = 1;
		char ch = getchar();

		while (!isdigit(ch)) {
			if (ch == '-') f = -1;
			ch = getchar();
		}

		while (isdigit(ch)) {
			x = (x << 3) + (x << 1) + (ch ^ 48);
			ch = getchar();
		}

		x = x * f;
	}

	inline void write(int x) {
		if (x < 0) {
			putchar('-');
			x = -x;
		}

		if (x > 9) write(x / 10);
		putchar((char)(x % 10 + 48));
	}

	inline void writefln(int x) {
		write(x);
		putchar(' ');
	}

	inline void writeln(int x) {
		write(x);
		putchar('\n');
	}

	template <typename ..._Tp>
	inline void read(int& x, _Tp& ...y) {
		read(x);
		read(y...);
	}

	template <typename ..._Tp>
	inline void writefln(int x, _Tp ...y) {
		writefln(x);
		writefln(y...);
	}

	template <typename ..._Tp>
	inline void writeln(int x, _Tp ...y) {
		writeln(x);
		writeln(y...);
	}
}

using namespace IO_fast_int32;

inline void solve() {
	read(n);
	int tot1 = 0, tot2 = 0, tot3 = 0;
	ans = 0;
	
	vector<int> max1, max2, max3;
	vector<node2> To(n + 1);
	for (int i = 1; i <= n; i ++) {
		int a, b, c;
		read(a, b, c);
		
		if (a >= b && a >= c) {
			ans += a;
			tot1 ++;
			max1.push_back(i);
			if (b >= c) To[i] = node2(a - b, 2);
			else To[i] = node2(a - c, 3);
		} else if (b >= a && b >= c) {
			ans += b;
			tot2 ++;
			max2.push_back(i);
			if (a >= c) To[i] = node2(b - a, 1);
			else To[i] = node2(b - c, 3);
		} else {
			ans += c;
			tot3 ++;
			max3.push_back(i);
			if (b >= a) To[i] = node2(c - b, 2);
			else To[i] = node2(c - a, 1);
		}
	}
	
	if (tot1 <= n / 2 && tot2 <= n / 2 && tot3 <= n / 2) {
		writeln(ans);
		return ;
	}
	
	if (tot1 > n / 2) {
		vector<PII> d2;
		for (int i = 0; i < max1.size(); i ++) {
			d2.push_back(make_pair(To[max1[i]].d2, i));
		}
		
		sort(d2.begin(), d2.end());
		vector<int> v2, v3;
		for (int i = 0; i < d2.size(); i ++) {
			tot1 --;
			ans -= To[max1[d2[i].second]].d2;
			if (tot1 == n / 2) break;
		}
		
		writeln(ans);
	} else if (tot2 > n / 2) {
		vector<PII> d2;
		for (int i = 0; i < max2.size(); i ++) {
			d2.push_back(make_pair(To[max2[i]].d2, i));
		}
		
		sort(d2.begin(), d2.end());
		for (int i = 0; i < d2.size(); i ++) {
			tot2 --;
			ans -= To[max2[d2[i].second]].d2;
			if (tot2 == n / 2) break;
		}
		
		writeln(ans);
	} else {
		vector<PII> d2;
		for (int i = 0; i < max3.size(); i ++) {
			d2.push_back(make_pair(To[max3[i]].d2, i));
		}
		
		sort(d2.begin(), d2.end());
		for (int i = 0; i < d2.size(); i ++) {
			tot3 --;
			ans -= To[max3[d2[i].second]].d2;
			if (tot3 == n / 2) break;
		}
		
		writeln(ans);
	}
}

int main(int argc, const char *argv[]) {
#ifdef LOCAL
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
#elif defined(DEBUG)
	freopen("club5.in", "r", stdin);
	freopen("test.out", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int t = 1;
	read(t);

	while (t --) {
		solve();
	}

	return 0;
}

