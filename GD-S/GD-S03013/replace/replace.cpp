#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
// #define int ll

 #define SUBMIT

constexpr int nmod = 4;
// constexpr int mod1 = 10400123, mod2 = 18801401, mod3 = 24302077;
// constexpr int t1 = 113, t2 = 71, t3 = 131;
int mods[] = {10000007, 10400123, 18801401, 24302077};
int tms[] = {131, 113, 71, 131};

#define mp make_pair

constexpr int maxn = 200010 * 3, maxspace = 200010 * 3;

int n, q;
string sub1[maxn], sub2[maxn];
string que1[maxn], que2[maxn];

int fstpow(int base, int exp) {
	int rtn = 1;
	while (exp) {
		if (exp & 1)
			rtn = (ll)rtn * base % mods[0];
		base = (ll)base * base % mods[0], exp >>= 1;
	}
	return rtn;
}

int max_occup = 0;
unordered_map<string, int> to_space;

int stringhashes[maxn]; 

vector<int> icc_space[maxspace];
map<int, int> icc_as_pre[maxspace];
map<int, int> icc_cnt_sub[maxspace];

inline int hash_to_space(const string &str) {
	int tos = to_space[str];
	if (tos == 0)
		tos = to_space[str] = ++max_occup;
	return tos;
}

inline int next_char(int hash, const char c) {
	int k = 0;
	hash = (ll)(hash * tms[k] + (c - 'a' + 1)) % mods[k];
	return hash;
}

inline pair<int, int> lics(const string &a, const string &b) {
	const int m = a.length() - 1;
	int rtn_l = 1, rtn_r = m;
	while (rtn_l <= m && a[rtn_l] == b[rtn_l]) {
//		cout << a[rtn_l] << b[rtn_l]<<'\n';
		++rtn_l;
	}
	while (rtn_r >= 1 && a[rtn_r] == b[rtn_r])
		--rtn_r;
	return mp(rtn_l, rtn_r);
}

signed main() {
#ifdef SUBMIT
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	 freopen("replace.in", "r", stdin); freopen("replace.out", "w", stdout);
//	freopen("replace3.in", "r", stdin); freopen("replace3.out", "w", stdout);
#endif

	cin >> n >> q;
	for (int i = 1; i <= n; ++i) {
		cin >> sub1[i] >> sub2[i];
		sub1[i] = " " + sub1[i];
		sub2[i] = " " + sub2[i];
	}
	for (int i = 1; i <= q; ++i) {
		cin >> que1[i] >> que2[i];
		que1[i] = " " + que1[i];
		que2[i] = " " + que2[i];
	}

	for (int i = 1; i <= n; ++i) {
		const auto p = lics(sub1[i], sub2[i]);	
		const int l = p.first, r = p.second;
		if (l > r)
			continue;
		const string ic1 = sub1[i].substr(l, r - l + 1);
		const string ic2 = sub2[i].substr(l, r - l + 1);
		const string icc = ic1 + ic2;
		const int hash_icc = hash_to_space(icc);
		icc_space[hash_icc].push_back(i);
		int hash = 0;
		for (int k = 1; k < sub1[i].length(); ++k) {
			hash = next_char(hash, sub1[i][k]);
			icc_as_pre[hash_icc][hash] += 1;
//			cerr << "fs" << sub1[i] << ' ' << hash_icc << ' ' << k << ' ' << hash << '\n';
		}
		stringhashes[i] = hash;
	}

 	for (int space_id = 1; space_id <= max_occup; ++space_id) {
		map<int, int> mp_here;
		sort(icc_space[space_id].begin(), icc_space[space_id].end(), [](int a, int b){return sub1[a].length() < sub1[b].length();});
		for (int id : icc_space[space_id]) {
			const string &sub1cur = sub1[id];
			const int hash_ = stringhashes[id];
			if (mp_here[hash_]) {
				mp_here[hash_] += 1;
				icc_cnt_sub[space_id][hash_] += 1;
				continue;
			} else {
				mp_here[hash_] = 1;
				icc_cnt_sub[space_id][hash_] = 1;
			}
//			cerr << space_id << ' ' << sub1[id] << ' ' << hash_ << '\n'; 
			int hash = 0;
			for (int k = 1; k < sub1[id].length() - 1; ++k) {
				hash = next_char(hash, sub1[id][k]);
//				cerr << "fs" << sub1[i] << ' ' << hash_icc << ' ' << k << ' ' << hash << '\n';
				if (k < sub1[id].length() - 1) {
					icc_cnt_sub[space_id][stringhashes[id]] += mp_here[hash];
				}
			}
		}
	}
	
	for (int i = 1; i <= q; ++i) {
		const auto p = lics(que1[i], que2[i]);
//		cout << que1[i] << ' ' << que2[i] << ' ' << p.first << ' ' << p.second << '\n';
		const int l = p.first, r = p.second; 
		const string ic1 = que1[i].substr(l, r - l + 1);
		const string ic2 = que2[i].substr(l, r - l + 1);
		const string icc = ic1 + ic2;
		const int hash_icc = hash_to_space(icc);

		vector<int> pres_h(que1[i].length(), 0);
		for (int j = 1; j < que1[i].length(); ++j) {
			pres_h[j] = next_char(pres_h[j - 1], que1[i][j]);
		}
		auto hash_que = [&pres_h](int l, int r) {
			constexpr int k = 0;
			return ((pres_h[r] - pres_h[l - 1] * (ll)fstpow(tms[k], r - l + 1)) % mods[k] + mods[k]) % mods[k];
		};
		
		int ans = 0;
		for (int j = l; j >= 1; --j) {
			int lt = r, rt = que1[i].length() - 1;
			while (lt <= rt) {
				const int mid = lt + rt >> 1;
				const int cur_hash = hash_que(j, mid);
//				cerr << i << ' ' << icc << ' ' << hash_icc << ' ' << j << ' ' << mid << ' ' << cur_hash << ' ' << icc_as_pre[hash_icc][cur_hash] << '\n';
				if (icc_as_pre[hash_icc][cur_hash])
					lt = mid + 1;
				else
					rt = mid - 1;
			}
			lt -= 1;
			
			if (lt < r) {
				continue;
			}
			const int cur_hash = hash_que(j, lt);
			int cont = icc_cnt_sub[hash_icc][cur_hash];
////			cout << ans << '\n';
			ans += cont;
//			cerr << "b " << i << ' ' << icc << ' ' << j << ' ' << lt << ' ' << cur_hash << ' ' << '\n';
		}
		cout << ans << '\n';
	}


//	for (int x = 10000000; x < 30000000; ++x) {
//		bool is_prime = true;
//		for (int j = 2; j <= 4000; ++j)
//			if (!(x % j)) {
//				is_prime = false;
//				break;
//			}
//		if (is_prime) {
//			cout << x << '\n';
//			x += 100000;
//		}
//	}

	return 0;
}
