#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#define ll long long
#define ull unsigned long long 
using namespace std;

const int Maxn = 2e5+5, Maxm = 5e6+5;
const ull Base = 37;

namespace Josh_zmf {
	
	int N, Q; ull hs[Maxm], base[Maxm];
//	unordered_map <ull, int> cnt;
	__gnu_pbds::gp_hash_table <ull, vector<pair<int, ull>>> have;
	
	inline ull hash(ull x, ull y) {
		return x*520002 + y;
	}
	
	inline ull get(int l, int r) {
		if(r < 0)	return 0;
		return hs[r] - (l ?hs[l-1]*base[r-l+1] :0);
	}
	
	int main() {
		cin>> N>> Q;
		for(int i=1; i<=N; i++) {
			static string tmp1, tmp2; cin>> tmp1>> tmp2;
//			if(tmp1 == "riu")	cerr<< "i: "<< i<< ", tmp1: "<< tmp1<< ", tmp2:"<< tmp2<< "\n";
			int l = 0, r = tmp1.size()-1;
			for(; l<=r and tmp1[l]==tmp2[l]; l++);
			for(; r>=l and tmp1[r]==tmp2[r]; r--);
			ull val1 = 0, val2 = 0;
			for(int j=l; j<=r; j++)	val1 = val1*Base + tmp1[j];
			for(int j=l; j<=r; j++)	val2 = val2*Base + tmp2[j];
			val2 = hash(val1, val2);
			for(int j=r+1; j<(int)tmp1.size(); j++)	val2 = val2*Base + tmp1[j];
			val1 = 0;
			for(int j=0; j<l; j++)	val1 = val1*Base + tmp1[j];
			have[val2].push_back({l, val1});
//			printf("have[%llu].push_back({%d, %llu})\n", val2, l, val1);
//			cnt[hash(val1, val2)]++;
//			printf("val:%llu, i:%d, l:%d, r:%d, val1:%llu, val2:%llu, s2::", hash(val1, val2), i, l+1, r+1, val1, val2);
//			for(int j=l; j<=r; j++)	printf("%c", tmp2[j]);
//			puts("");
		}
//		puts("__________________");
		base[0] = 1;
		for(int i=1; i<Maxn-2; i++)	base[i] = base[i-1]*Base;
		for(int i=1; i<=Q; i++) {
			static string tmp1, tmp2; cin>> tmp1>> tmp2;
			int l = 0, r = tmp1.size()-1;
			for(; l<=r and tmp1[l]==tmp2[l]; l++);
			for(; r>=l and tmp1[r]==tmp2[r]; r--);
			ull val1 = 0, val2 = 0;
			for(int j=l; j<=r; j++)	val1 = val1*Base + tmp1[j];
			for(int j=l; j<=r; j++)	val2 = val2*Base + tmp2[j];
			val2 = hash(val1, val2), hs[0] = tmp1[0];
			for(int j=1; j<l; j++)	hs[j] = hs[j-1]*Base + tmp1[j];
			int ans = 0;
//			printf("i:%d\n", i);
//			if(i == 24192)	cerr<< "s1:: "<< tmp1<< ", s2:: "<< tmp2<< '\n';
			for(int j=r; j<(int)tmp1.size(); j++) {
				for(auto tmp: have[val2]) {
					int len = tmp.first; ull h = tmp.second;
//					if(i == 24192) {
//						printf("have[%llu]:{%d, %llu}, l:%d, r:%d, j:%d, size:%d\n", val2, len, h, l, r, j, (int)tmp1.size());
//						if(!h)	assert(0);
//					}
					if(len<=l and get(l-len, l-1) == h)	ans++;
				}
				if(j+1<(int)tmp1.size())	val2 = val2*Base + tmp1[j+1];
			}
			cout<< ans<< '\n';
//			cout<< cnt[hash(val1, val2)]<< '\n';
//			printf("val:%llu, i:%d, l:%d, r:%d, val1:%llu, val2:%llu, s1::", hash(val1, val2), i, l+1, r+1, val1, val2);
//			for(int j=l; j<=r; j++)	printf("%c", tmp1[j]);
//			puts("");
//			printf("val:%llu, i:%d, l:%d, r:%d, val1:%llu, val2:%llu\n", hash(val1, val2), i, l+1, r+1, val1, val2);
//			printf("i:%d, l:%d, r:%d, val1:%llu, val2:%llu, val:%llu\n", i, l+1, r+1, val1, val2, hash(val1, val2));
		}
		return 0;
	}
	
}

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	Josh_zmf::main();
	return 0;
}
