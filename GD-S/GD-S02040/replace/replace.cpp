#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;

ll getInt() {
	ll s = 0, f = 1;
	char c = getchar();
	while (!isdigit(c)) {
		if (c == '-') f = -1;
		c = getchar();
	}
	
	while (isdigit(c)) {
		s = s * 10 + c - '0';
		c = getchar(); 
	}
	
	return s * f;
}

ll n, q;

const ull bas = 26;

ull mi[2000010];

void init() {
	mi[1] = 1;
	for (int i = 2; i <= 2000000; ++i) {
		mi[i] = mi[i - 1] * bas;
	}
}

struct String {
	ull val;
	ll len;
	
	void getString() {
		len = 0ll;
		val = 0ull;
		char c = getchar();
		while (!islower(c)) {
			c = getchar();
		}
		while (islower(c)) {
			++len;
			val += (c - 'a') * mi[len];
			c = getchar();
		}
	}
	
	bool operator==(String t) {
		return (val == t.val && len == t.len);
	}
	
	String cut(ll begin, ll length) {
		return {val / mi[begin] % mi[length + 1], length};
	}
	
	String cutToEnd(ll begin) {
		return {val / mi[begin], len - begin + 1};
	}
	
	bool cutable(ll begin, ll length) {
		return begin + length - 1 <= len;
	}
	
	String replace(ll begin, String newString) {
		return {val - cut(begin, newString.len).val * mi[begin] + newString.val * mi[begin], len};
	}
};


String rule[200010][2];
String s, e;

ll ans = 0;

void check(String t) {
	for (int l = 1; l <= t.len; ++l) {
		for (int i = 1; i <= n; ++i) {
			if (t.cutable(l, rule[i][0].len) && t.cut(l, rule[i][0].len) == rule[i][0]) {
				if (e == t.replace(l, rule[i][1])) {
					++ans;
				}
			} 
		} 
	} 
}

void ssert(bool f) {
	if (!f) {
		cerr << "error" << endl;
	} else {
		cerr << "pass" << endl; 
	}
}



ll dif[200010];

ll findDif(String x, String y) {
	ll l = 1, r = x.len, res = 0;
	while (l <= r) {
		ll mid = (l + r) / 2;
		if (x.cut(1, mid) == y.cut(1, mid)) {
			l = mid + 1; 
		} else {
			r = mid - 1;
			res = mid;
		}
	}
	return res;
}

void test() {
	String x, y, z;
	x.getString();
	y.getString();
	
	printf("%lld\n", findDif(x, y)); 
}

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	
	init();
	
//	test();
	
	n = getInt();
	q = getInt();
	
	for (int i = 1; i <= n; ++i) {
		rule[i][0].getString();
		rule[i][1].getString();
	} 
	
	if (false) {
		for (int j = 1; j <= q; ++j) {
			s.getString();
			e.getString();
			ans = 0;
			check(s);
			printf("%lld\n", ans);
		}
	} else {
		for (int i = 1; i <= n; ++i) {
			dif[i] = findDif(rule[i][0], rule[i][1]);
		}
		
		
		for (int j = 1; j <= q; ++j) {
			ans = 0;
			s.getString();
			e.getString();
			ll d = findDif(s, e);
			for (int i = 1; i <= n; ++i) {
				ll pos = d - dif[i] + 1;
				ll len_ = rule[i][0].len;
				if (dif[i] <= d && s.cutable(pos, len_) && s.cut(pos, len_) == rule[i][0]
					&& e.cut(pos, len_) == rule[i][1] && s.cutToEnd(pos + len_) == e.cutToEnd(pos + len_)) {
//						cout << i << " " << pos << " " << len_ << endl;
					++ans;	
				}
			}
			printf("%lld\n", ans);
		}
	}
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
