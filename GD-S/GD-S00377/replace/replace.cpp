#include <iostream>
#include <algorithm>
#include <bitset>
#include <string>
#include <vector>

#ifdef KOISHI
#include <bits/stdc++.h>
#endif

using namespace std;
using lint = long long;
using ull = unsigned long long;
const int maxl = 5e6 + 9;
const int maxn = 2e5 + 9;

//char buf[1<<20], *p1=buf, *p2=buf;
//#define getc() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<20,stdin))==p1?EOF:*p1++)
//lint read(){
//	lint rs = 0, c = 0;
//	while ('9' < c || c < '0'){
//		c = getc();
//	} while (!('9' < c || c < '0')){
//		rs = rs*10 + (c^48), c = getc();
//	} return rs;
//}

#define rep(i, j, k) for ((i) = (j); (i) <= (k); ++(i))



int n, qq;
string s1[maxn], s2[maxn];
string t1, t2;

int vn, rt = 1;
int to[maxl][26];
int fail[maxl];
vector<int> ende[maxl];
int sat[maxn];

void insert(int idx){
	int i, j;
	int len = s1[idx].size();
	
	j = rt;
	rep (i, 0, len-1){
		int id = s1[idx][i] - 'a';
		if (!to[j][id]){
			to[j][id] = ++vn;
			fail[vn] = 0;
		}
		j = to[j][id];
	}
	
	ende[j].push_back(idx);
	sat[idx] = j;
}

int que[maxn], h, t;
void init(){
	int i, j;
	
	que[h=t=1] = rt, fail[rt] = rt;
	while (h <= t){
		int nw = que[++h];
		
		rep (i, 0, 25){
			if (to[nw][i]) que[++t] = to[nw][i];
			int nxt = (to[fail[nw]][i]? to[fail[nw]][i] : rt);
			(to[nw][i] ? fail[to[nw][i]] : to[nw][i]) = nxt;
		}
	}
}

const ull base1 = 5140007;
const ull mod1 = 998244353;
const ull base2 = 993244853;
const ull mod2 = 1e9 + 7;

ull hs2a[maxn], hs2b[maxn];
ull bp1[maxn], bp2[maxn];

void inithash(){
	int i, j;
	
	rep (i, 1, n){
		for (auto c : s2[i]){
			hs2a[i] = (hs2a[i] * base1 + c) % mod1;
			hs2b[i] = (hs2b[i] * base2 + c) % mod2;
		}
	}
	
	bp1[0] = bp2[0 = 0;
	rep (i, 1, maxn-2){
		bp1[i] = bp1[i-1] * base1 % mod1;
		bp2[i] = bp2[i-1] * base2 % mod2;
	}
}

ull t1ha, t2ha;
ull t1hb, t2hb;
void hasht(){
	
	for (auto c : t1){
		t1ha = (t1ha * base1 + c) % mod1;
	}
	for (auto c : t1){
		t1hb = (t1hb * base2 + c) % mod2;
	}
	for (auto c : t2){
		t2ha = (t2ha * base1 + c) % mod1;
	}
	for (auto c : t2){
		t2hb = (t2hb * base2 + c) % mod2;
	}
}

vector<int> rcnt[maxn];

void march(){
	int i, j;
	int len = t1.size();
	
	j = rt;
	rep (i, 0, len-1){
		int id = t1[i] - 'a';
		j = to[j][id];
		if (ende[j].size()){
			rcnt[j].push_back(i);
		}
	}
	
	rep (i, 1, n){
		if (ende[sat[i]].size()){
			int nw = sat[i];
			for (j = fail[nw]; j != rt; j = fail[j]){
				if (ende[j].size()) for (auto ud : rcnt[nw]){
					rcnt[j].push_back(ud);
				}
			}
		}
	}
	
	rep (i, 1, n){
		int len = s1[i].size();
		int nw = sat[i];
		for (auto rs : rcnt[nw]){
			int hasht1 = t1ha;
		}
	}
}


int main(){
	int i, j;

#ifdef KOISHI
	freopen("replace1.in", "r", stdin);
	freopen("out.out", "w", stdout);
#else
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
#endif

	cin >> n >> q;
	rep (i, 1, n){
		cin >> s1[i] >> s2[i];
		insert(s1[i], i);
	}
	
	init();
	
	while (q--){
		cin >> t1 >> t2;
		
		printf("%lld\n", ans);
	}
	
#ifdef KOISHI
	freopen("log.out", "w", stdout); 
	system("fc out.out replace1.ans");
#endif
	
	return 0;
}

/*
	啊哈哈哈哈哈哈哈哈哈哈哈啊哈 
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	忘了哈希和ac自动机的神人，并且正解大概并非 
	
	
	
	return AFO 
*/
