#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <string>

using namespace std;

const int maxs = 2005 * 26, maxn = 1e3 + 5;

struct Trie{
	int nxt[maxs][26], cnt;
	bool exist[maxs];
	int insert(char s[], int len){
		int p = 0;
		for(int i = 0; i < len; ++i){
			int c = s[i] - 'a';
			if(!nxt[p][c]) nxt[p][c] = ++cnt;
			p = nxt[p][c];
		}
		exist[p] = 1;
		return p;
	}
	int insert(string s, int len){
		int p = 0;
		for(int i = 0; i < len; ++i){
			int c = s[i] - 'a';
			if(!nxt[p][c]) nxt[p][c] = ++cnt;
			p = nxt[p][c];
		}
		exist[p] = 1;
		return p;
	}
	
	bool find(char s[], int len){
		int p = 0;
		for(int i = 0; i < len; ++i){
			int c = s[i] - 'a';
			if(!nxt[p][c]) return 0;
			p = nxt[p][c];
		}
		return exist[p];
	}
	bool find(string s, int len){
		int p = 0;
		for(int i = 0; i < len; ++i){
			int c = s[i] - 'a';
			if(!nxt[p][c]) return 0;
			p = nxt[p][c];
		}
		return exist[p];
	}
}t;

int n, q;
vector<string>S[maxs];
char tmp[maxn << 1], tmp1[maxn << 1];
void solve() {
	scanf("%d%d", &n, &q);
	for(int i = 1; i <= n; ++i){
		scanf("%s", tmp);
		int len = strlen(tmp);
		S[t.insert(tmp, len)].push_back(string(tmp));
	}
	int ans = 0;
	for(int i = 1; i <= q; ++i){
		scanf("%s%s", tmp, tmp1);
		int len = strlen(tmp);
		for(int j = 0; j < len; ++j)
			for(int k = len - 1; k >= j; --k){
				string s = "", s1 = "", s2 = "";
				for(int z = 0; z < j; ++z) s += tmp[z];
				for(int z = j; z <= k; ++z) s1 += tmp[z];
				for(int z = k + 1; z < len; ++z) s2 += tmp[z];
				int tttt = t.find(s1, k - j + 1);
				if(tttt){
					for(auto it : S[tttt])
						ans += (s + it + s2) == tmp1;
				}
			}
		printf("%d\n", ans);
	}
}

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	solve();
	return 0;
}