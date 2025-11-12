#include <bits/stdc++.h>
using namespace std;

const int MXN = 2e5;
const int P = 1e9 + 7;

int n, q, ns[MXN];
string s[MXN][2], t[MXN][2];
int ls[MXN], rs[MXN], lt[MXN], rt[MXN];
unsigned long long pw[MXN];
pair< unsigned long long, unsigned long long > h[MXN];
vector< pair< unsigned long long, unsigned long long > > nums;
vector< int > ips[MXN];
vector< int > ipt[MXN];
bitset< MXN > resl, resr;
map< unsigned long long, bool > visl;
map< unsigned long long, bitset< MXN > > bl;
map< unsigned long long, bool > visr;
map< unsigned long long, bitset< MXN > > br;

int main(){
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	int i, j, k;
	cin >> n >> q;
	pw[0] = 1;
	for(i = 1;i < n;++i) pw[i] = pw[i - 1] * P;
	for(i = 0;i < n;++i){
		cin >> s[i][0] >> s[i][1];
		ls[i] = rs[i] = -1;
		for(j = 0;j < (int)s[i][0].size();++j)
			if(s[i][0][j] != s[i][1][j]){
				ls[i] = j;
				break;
			}
		for(j = (int)s[i][0].size() - 1;j >= 0;--j)
			if(s[i][0][j] != s[i][1][j]){
				rs[i] = j;
				break;
			}
		if(ls[i] == -1) continue;
		for(j = ls[i];j <= rs[i];++j){
			h[i].first += s[i][0][j] * pw[j - ls[i]];
			h[i].second += s[i][1][j] * pw[j - ls[i]];
		}
		nums.push_back(h[i]);
	}
	sort(nums.begin(), nums.end());
	nums.erase(unique(nums.begin(), nums.end()), nums.end());
	for(i = 0;i < n;++i){
		int ip = lower_bound(nums.begin(), nums.end(), h[i]) - nums.begin();
		ips[ip].push_back(i);
	}
	for(i = 0;i < q;++i){
		cin >> t[i][0] >> t[i][1];
		if(t[i][0].size() != t[i][1].size()) continue;
		lt[i] = rt[i] = -1;
		for(j = 0;j < (int)t[i][0].size();++j)
			if(t[i][0][j] != t[i][1][j]){
				lt[i] = j;
				break;
			}
		for(j = (int)t[i][0].size() - 1;j >= 0;--j)
			if(t[i][0][j] != t[i][1][j]){
				rt[i] = j;
				break;
			}
		pair< unsigned long long, unsigned long long > ht = {0, 0};
		for(j = lt[i];j <= rt[i];++j){
			ht.first += t[i][0][j] * pw[j - lt[i]];
			ht.second += t[i][1][j] * pw[j - lt[i]];
		}
		int ip = lower_bound(nums.begin(), nums.end(), ht) - nums.begin();
		if(ip == (int)nums.size() || ht != nums[ip]) continue;
		ipt[ip].push_back(i);
	}
	for(i = 0;i < (int)nums.size();++i){
		visl.clear();
		bl.clear();
		visr.clear();
		br.clear();
		for(j = 0;j < (int)ips[i].size();++j){
			int v = ips[i][j];
			unsigned long long hs = 0;
			for(k = ls[v];k >= 0;--k) hs += s[v][0][k] * pw[ls[v] - k];
			visl[hs] = 1;
			bl[hs][v] = 1;
			hs = 0;
			for(k = ls[v];k < (int)s[v][0].size();++k) hs += s[v][0][k] * pw[k - ls[v]];
			visr[hs] = 1;
			br[hs][v] = 1;
		}
		for(j = 0;j < (int)ipt[i].size();++j){
			int v = ipt[i][j];
			unsigned long long ht = 0;
			resl = 0;
			resr = 0;
			for(k = lt[v];k >= 0;--k){
				ht += t[v][0][k] * pw[lt[v] - k];
				if(visl[ht]) resl |= bl[ht];
			}
			ht = 0;
			for(k = lt[v];k < (int)t[v][0].size();++k){
				ht += t[v][0][k] * pw[k - lt[v]];
				if(visr[ht]) resr |= br[ht];
			}
			ns[v] = (resl & resr).count();
		}
	}
	for(i = 0;i < q;++i) printf("%d\n", ns[i]);
	return 0;
}
