#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int inf = 0x3f3f3f3f;
const ll INF = 0x3f3f3f3f3f3f3f3fll;


#ifdef _Joler_
#define debug(x) cout<<(#x)<<" = "<<(x)<<'\n'
#else
#define debug(x) ;
#define cin fin
#define cout fout
ifstream fin("replace.in");
ofstream fout("replace.out");
#endif

const int mod = 1e9 + 21;
const int base = 541;

int check(int x) {
	for (int i = 2; i * i <= x; i++) {
		if (x % i == 0) return 0;
	}
	return 1;
}
struct Hash{
	int n;
	vector <int> v, b;
	hash(){}
	void init(const string& s) {
		n = s.size();
		v.resize(n + 1);
		b.resize(n + 1, 1);
		for (int i = 1; i <= n; i++) {
			b[i] = (1ll * b[i - 1] * base) % mod;
			v[i] = (1ll * v[i - 1] * base + s[i - 1]) % mod; 
		}
	}
	
	int get(int l, int r) {
		if (l > r) return 0;
		l++, r++;
		return (0ll + v[r] + mod - 1ll * v[l - 1] * b[r - l + 1] % mod) % mod;
	}
};

int h1(const string&s) {
	ll res = 0;
	for (const auto&c : s) {
		res = (res * base + c) % mod;
	}
	return res;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, q;
	cin >> n >> q;
	vector<array<int, 3> > vh1(n);
//	vector<array<string, 2> > vs(n);
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		vh1[i][0] = s.size();
		vh1[i][1] = h1(s);
		cin >> s;
		vh1[i][2] = h1(s);
//		cin >> vs[i][0] >> vs[i][1];
	}
	sort(vh1.begin(), vh1.end(), [&](const array<int, 3>&a, const array<int, 3>& b){
		return a[0] > b[0];
	});
	
	for (int _i = 0; _i < q; _i++) {
		string s2, s3;
		cin >> s2 >> s3;
		if (s2.size() != s3.size()) {
			cout << "0\n";
			continue;
		}
		int m = s2.size();
		int mx = -1, mi = m;
		for (int j = 0; j < m; j++) {
			if (s2[j] != s3[j]) {
				mx = max(mx, j);
				mi = min(mi, j);
			}
		}
		Hash nh2, nh3;
		nh2.init(s2);
		nh3.init(s3);
		int st = 0;
		int l = 0;
		int ans = 0;
		for (int j = 0; j <= mi; j++) {
			while (l < n && j + vh1[l][0] - 1 >= mx) {
				l++;
			}
			while (st < l && j + vh1[st][0] > m) st++;
			for (int i = st; i < l; i++) {
//				if (vh1[i][1] == nh2.get(j, j + vh1[i][0] - 1) 
//					&& vh1[i][2] == nh3.get(j, j + vh1[i][0] - 1)) {
//					debug(_i);
//					debug(j);
//					debug(i);
//				}
				ans += vh1[i][1] == nh2.get(j, j + vh1[i][0] - 1) 
					&& vh1[i][2] == nh3.get(j, j + vh1[i][0] - 1);
//				if (j + len <= m) ;//ans += 1;//s[0].substr(j, len) == vs[i][0] && s[1].substr(j, len) == vs[i][1];
			}
		}
		cout << ans << '\n';
	}
	
	return 0;
}
