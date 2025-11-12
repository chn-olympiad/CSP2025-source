#include<algorithm>
#include<stdio.h>
#include<queue>
#include<iostream>
#include<string.h>
#define ll long long
#define NN 200005
#define N 5000005
#include<vector>
#define ull unsigned long long

using namespace std;

ll rd() {
	char c=getchar(); ll x=0, y=1;
	while(!(c >= '0' && c <= '9' || c == '-')) c=getchar();
	if(c == '-') y=-1, c=getchar();
	while(c >= '0' && c <= '9') x=x*10+c-'0', c=getchar();
	return x*y;
}
int n, q;
string s1[NN], s2[NN];
ull g1[NN], g2[NN]; 
int pre[N], nxt[N];
ull pw[N];

struct ACAM {
	int son[N][26], fa[N];
	int cnt=1;
	vector<int> vec[N];
	void insert(string str, int x) {
		int now=1;
		for(int i=0; i<str.size(); i++) {
			int c=str[i]-'a';
			if(!son[now][c]) son[now][c]=++cnt;
			now=son[now][c]; 
		}
		vec[now].push_back(x);
	}
	int head[N], to[N], nex[N], m1;
	void add(int u, int v) {to[++m1]=v, nex[m1]=head[u], head[u]=m1;}
	void build() {
		queue<int> que;
		for(int i=0; i<26; i++) {
			if(son[1][i]) fa[son[1][i]]=1, que.push(son[1][i]);
			else son[1][i]=1;
		}
		while(!que.empty()) {
			int now=que.front(); que.pop();
			for(int i=0; i<26; i++) {
				if(son[now][i]) fa[son[now][i]]=son[fa[now]][i], que.push(son[now][i]), add(now, son[now][i]);
				else son[now][i]=son[fa[now]][i];
			}
		}
	}
} A1, A2;

ull h1[N], h2[N];
ull ask(int l, int r) {return h2[r]-h2[l]*pw[r-l];}
ll solve() {
	string t1, t2;
	cin >> t1 >> t2;
	if(t1.size() != t2.size()) return 0;
	pre[0] = 1;
	for(int i=1; i<=t1.size(); i++) {
		pre[i] = pre[i-1];
		h1[i]=h1[i-1]*pw[1]+(t1[i-1]-'a'+1);
		h2[i]=h2[i-1]*pw[1]+(t2[i-1]-'a'+1);
		if(t1[i-1] != t2[i-1]) pre[i]=0;
	}
	nxt[t1.size()+1] = 1;
	for(int i=t1.size(); i>0; i--) {
		nxt[i] = nxt[i+1];
		if(t1[i-1] != t2[i-1]) nxt[i]=0;
	}
	int now=1;
	ll ans=0;
	for(int i=1; i<=t1.size(); i++) {
		now = A1.son[now][t1[i-1]-'a'];
		if(!nxt[i+1]) continue;
		int cur=now;
		while(cur) {
			for(int j=0; j<A1.vec[cur].size(); j++) {
				int st = A1.vec[cur][j];
				if(!pre[i-s1[st].size()]) break;
				if(g2[st] == ask(i-s1[st].size(), i)) ans++;
			}
			cur=A1.fa[cur];
		}
	}
	return ans;
//	printf("%lld\n", ans);
}
int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	pw[0]=1; pw[1]=13331; for(int i=1; i<N; i++) pw[i]=pw[i-1]*pw[1];
	n=rd(), q=rd();
	for(int i=1; i<=n; i++) {
		cin>>s1[i], cin>>s2[i];
		A1.insert(s1[i], i);
		for(int j=0; j<s1[i].size(); j++) g1[i]=g1[i]*pw[1]+(s1[i][j]-'a'+1);
		for(int j=0; j<s1[i].size(); j++) g2[i]=g2[i]*pw[1]+(s2[i][j]-'a'+1);
	}
	A1.build();
	for(int i=1; i<=q; i++) {
		printf("%lld\n", solve());
	}
	return 0;
}

