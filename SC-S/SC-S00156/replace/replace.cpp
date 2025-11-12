#include <iostream>
#include <cstdio>
#include <map>
#include <utility>
#include <cstring>
using std::pair;
using std::string;
using std::make_pair;
const int L = 5000005, INF = 0x7f7f7f7f;
char S1[L], S2[L];
std::map<pair<string, string> , int> mp;
void Getlr(int &l, int &r, int lenth) {
	for(int j = 0; j < lenth; ++j) {
		if(S1[j] != S2[j]) {
			l = std::min(l, j);
			r = std::max(r, j);
		}
	}
}
int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out","w",stdout);
	int n, q;
	string s1, s2;
	scanf("%d%d", &n, &q);
	for(int i = 1; i <= n; ++i) {
		scanf("%s%s", S1, S2);
		s1 = s2 = "";
		int lenth = strlen(S1);
		for(int j = 0; j < lenth; ++j) {s1 += S1[j]; s2 += S2[j];}
		
		auto pr = std::make_pair(s1, s2);
		if(mp.find(pr) != mp.end()) mp[pr]++;
		else mp.insert(std::make_pair(pr, 1));
	}
	for(int i = 1; i <= q; ++i) {
		scanf("%s%s", S1, S2);
		int lenth = strlen(S1);
		if(lenth != strlen(S2)) {
			printf("0\n");
			continue;
		} 
		int l = INF, r = 0;
		
		Getlr(l, r, lenth);
		int ans = 0;
		for(int j = 0; j <= l; ++j) {
			s1 = s2 = "";
			for(int k = j; k < r; ++k) {
				s1 += S1[k];
				s2 += S2[k];
			}
			for(int k = r; k < lenth; ++k) {
//				s1 = s2 = "";
				s1 += S1[k];
				s2 += S2[k];
//				for(int l = j; l <= k; ++l) {
//					s1 += S1[l];
//					s2 += S2[l];
//				}
//				std::cout << "FIND " <<s1 <<" " << s2 << '\n';
				auto pr = std::make_pair(s1, s2);
				if(mp.find(pr) != mp.end()) ans += mp[pr];
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}