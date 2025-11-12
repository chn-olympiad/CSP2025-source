#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;
int mian(); int main() { return mian(); }

#define ll long long
const int N = 2e5 + 25, L = 2e6 + 26;
int n, Q, _;

char S1[N], S2[N];
int lenS[N];

struct AC {
	int fail;
	int son[26];
	// vector<int> ed;
	vector<int> sub;
} o1[L], o2[L];
int Size1, Size2;
int pos1[N], pos2[N];
void Insert(const int I) {
	int now1 = 0, now2 = 0, m = strlen(S1 + 1);
	for(int i = 1; i <= m; ++i) {
		int c1 = S1[i] - 'a', c2 = S2[i] - 'a';
		int & v1 = o1[now1].son[c1];
		int & v2 = o2[now2].son[c2];
		if(!v1) v1 = ++Size1;
		if(!v2) v2 = ++Size2;
		// cout<<now1<<"    "<<now2<<" "<<c2<<endl;
		now1 = v1, now2 = v2;
	}
	// o1[now1].ed.push_back(I);
	// o2[now2].ed.push_back(I);
	pos1[I] = now1, pos2[I] = now2;
}

vector<int> pt[L];

bool cmp(const int A, const int B) { return lenS[A] == lenS[B] ? A > B : lenS[A] > lenS[B]; }
void build1() {
	queue<int> q;
	for(int i = 0; i < 26; ++i) if(o1[0].son[i]) q.push(o1[0].son[i]), o1[o1[0].son[i]].fail = 0;
	while(!q.empty()) {
		const int u = q.front(); q.pop();
		// cout<<u<<" "<<o1[u].fail<<endl;
		for(int i = 0; i < 26; ++i) {
			int & v = o1[u].son[i];
			// cout<<u<<" "
			if(!v) v = o1[ o1[u].fail ].son[i];
			else o1[v].fail = o1[ o1[u].fail ].son[i], q.push(v);
		}
	}
	// exit(0);
	for(int i = 1; i <= n; ++i) {
		int u = pos1[i];
		pt[u].push_back(i);
		
	}
	for(int u = 1; u <= Size1; ++u) {
		int now = u;
		while(now) {
			// cout<<i<<"    "<<u<<endl;
			for(auto i : pt[now]) o1[u].sub.push_back(i);
			now = o1[now].fail;
		}
	}
	for(int i = 1; i <= Size1; ++i) sort(o1[i].sub.begin(), o1[i].sub.end(), cmp), pt[i].clear();
}
void build2() {
	queue<int> q;
	for(int i = 0; i < 26; ++i) if(o2[0].son[i]) q.push(o2[0].son[i]), o2[o2[0].son[i]].fail = 0;
	// cout<<"csdcds"; for(int i = 0; i < 26; ++i) if(o2[0].son[i]) cout<<i<<" ";; puts("");
	while(!q.empty()) {
		const int u = q.front(); q.pop();
		for(int i = 0; i < 26; ++i) {
			int & v = o2[u].son[i];
			if(!v) v = o2[ o2[u].fail ].son[i];
			else o2[v].fail = o2[ o2[u].fail ].son[i], q.push(v);
		}
	}
	for(int i = 1; i <= n; ++i) {
		int u = pos2[i];
		pt[u].push_back(i);
		
	}
	for(int u = 1; u <= Size2; ++u) {
		int now = u;
		while(now) {
			// cout<<i<<"    "<<u<<endl;
			for(auto i : pt[now]) o2[u].sub.push_back(i);
			now = o2[now].fail;
		}
	}
	for(int i = 1; i <= Size2; ++i) sort(o2[i].sub.begin(), o2[i].sub.end(), cmp), pt[i].clear();
}

char T1[N], T2[N];
int lcp, lcs;
int ans[N], lenT;
void putask(const int I) {
	int now1 = 0, now2 = 0;
	for(int i = 1; i <= lenT; ++i) {
		int c1 = T1[i] - 'a', c2 = T2[i] - 'a';
		now1 = o1[now1].son[c1];
		now2 = o2[now2].son[c2];
		// cout<<now1<<"    "<<now2<<" "<<c2<<endl;
		if(i + 1 >= lcs) {
			int p1 = 0, p2 = 0;
			vector<int> & v1 = o1[now1].sub;
			vector<int> & v2 = o2[now2].sub;
			// for(auto xf : v1) cout<<xf<<" ";; puts("");
			// for(auto xf : v2) cout<<xf<<" ";; puts("");
			while(p1 < (int)v1.size() and p2 < (int)v2.size()) {
				if( min( lenS[v1[p1]], lenS[v2[p2]] ) < i - lcp ) break;
				if(v1[p1] == v2[p2]) { ans[I]++; p1++, p2++; }
				if( cmp(p1, p2) ) p2++;
				else p1++;
			}
		}
	}
}

int mian() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	// cout<<sizeof(o1)<<endl;
	_ = scanf("%d%d", &n, &Q);
	for(int i = 1; i <= n; ++i) {
		_ = scanf("%s", S1 + 1);
		_ = scanf("%s", S2 + 1);
		lenS[i] = strlen(S1 + 1);
		Insert(i);
		// cout<<pos1[i]<<" "<<pos2[i]<<endl;
	}
	build1(); build2();
	for(int i = 1; i <= Q; ++i) {
		lcp = 0, lcs = 0;
		_ = scanf("%s%s", T1 + 1, T2 + 1);
		if(strlen(T1 + 1) != strlen(T2 + 1)) { ans[i] = 0; continue; }
		lenT = strlen(T1 + 1);
		for(int j = 1; j <= lenT; ++j) if(T1[j] != T2[j]) break; else lcp++;
		for(int j = lenT; j >= 1; --j) if(T1[j] != T2[j]) break; else lcs++;
		lcs = lenT - lcs + 1;
		putask(i);
	}
	for(int i = 1; i <= Q; ++i) printf("%d\n", ans[i]);
	return 0;
}/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb
*/