#include<bits/stdc++.h>
#define int long long
using namespace std;

using ull = unsigned long long;

int n;
string base[200010];
ull hashes[200010];
ull replaced_hashes[200010];
ull target_hash[5000010];
const int p1 = 233;
ull table_p1[5000010];

ull get_hash(const string&a, int base) {
	ull hash = 0;
	for(auto c:a) {
		hash *= base;
		hash += c - 'a';
	}
	return hash;
}

ull subhash(int start, int end) {
	int len = end - start + 1;
	return target_hash[end] - target_hash[start - 1] * table_p1[len];
}

void write(int t) {
	if(t < 10) {
		putchar(t + '0');
	} else {
		write(t / 10);
		putchar(t % 10 + '0');
	}
}

signed main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, q;
	cin >> n >> q;
	table_p1[0] = 1;
	for(int i = 1; i <= 5000000; ++i) {
		table_p1[i] = table_p1[i - 1] * p1;
	}
	for(int i = 1; i <= n; ++i) {
		string a, b;
		cin >> base[i] >> b;
		hashes[i] = get_hash(base[i], p1);
		replaced_hashes[i] = get_hash(b, p1);
	}
	for(int i = 1; i <= q; ++i) {
		int ans = 0;
		string t1, t2;
		cin >> t1 >> t2;
		if(t1.length() != t2.length()) {
			cout << 0 << '\n';
			continue;
		}
		for(size_t i = 1; i <= t1.length(); ++i) {
			char c = t1[i - 1];
			target_hash[i] = target_hash[i - 1] * p1 + c - 'a';
		}
		ull t2hash = get_hash(t2, p1);
		for(int i = 1; i <= n; ++i) {
			for(size_t j = 1; j <= t1.length(); ++j) {
				if(j + base[i].length() - 1 > t1.length()) {
					break;
				}
				// try matching
				int start = j;
				int end = j + base[i].length() - 1;
				int len = end - start + 1;
				auto sub = subhash(start, end);
				if(sub == hashes[i]) {
					// try replacing
					ull new_hash = (target_hash[start - 1] * table_p1[len] + replaced_hashes[i]) * table_p1[t1.length() - end] + subhash(end + 1, t1.length());
					if(new_hash == t2hash) {
						ans++;
					}
				}
			}
		}
		write(ans);
		putchar('\n'); 
	}
	return 0;
}
