#include<bits/stdc++.h>
#define ll long long
#define PR pair<int, int>
#define fi first
#define se second
using namespace std;

bool begin_mem;

const int MAXM = 5e6+5, MAXN = 2e5+5;
const ll Mod1 = 1e9+7, Mod2 = 1e9+9, P = 131;
int n, q, m, ans[MAXN];
char s1[MAXM], s2[MAXM];

struct HS{
	ll v1, v2;
	HS operator + (const char &tmp)const{
		return {(v1*P+tmp)%Mod1, (v2*P+tmp)%Mod2};
	}
	bool operator < (const HS &tmp)const{
		if(v1 != tmp.v1)	return v1 < tmp.v1;
		return v2 < tmp.v2;
	}
};
map<HS, int> mp1, mp2;

inline HS Calc(int l, int r){
	HS ans = {0, 0};
	for(int i = l; i <= r; i++)	ans = ans+s1[i];
	for(int i = l; i <= r; i++)	ans = ans+s2[i];
	return ans;
}

inline void Get(int &l, int &r){
	l = 1, r = m;
	while(l <= m and s1[l] == s2[l])	++l;
	while(r >= 1 and s1[r] == s2[r])	--r;
	return;
}

//-----

int tot, dfn_tot, c[MAXM];

inline void Add(int x, int v){
	for(int i = x; i <= dfn_tot; i += i&-i)	c[i] += v;
	return;
}

inline int Query(int x){
	int ans = 0;
	for(int i = x; i; i -= i&-i)	ans += c[i];
	return ans;
}

//-----

int sz[MAXM], dfn[MAXM];

struct Node{
	int ch[26];
	vector<int> C;
	vector<PR> Q;
	#define ch(x, y)	tree[x].ch[y]
	#define C(x)		tree[x].C
	#define Q(x)		tree[x].Q
} tree[MAXM];

inline void Insert(int p, int q, int l, int r){
	for(int i = l-1; i >= 1; i--){
		int c = s1[i]-'a';
		assert(s1[i] == s2[i]);
		if(!ch(p, c))	ch(p, c) = ++tot;
		p = ch(p, c);
	}
	for(int i = r+1; i <= m; i++){
		int c = s1[i]-'a';
		assert(s1[i] == s2[i]);
		if(!ch(q, c))	ch(q, c) = ++tot;
		q = ch(q, c);
	}
	C(p).push_back(q);
	return;
}

inline void DFS1(int pt){
	dfn[pt] = ++dfn_tot, sz[pt] = 1;
	for(int i = 0; i < 26; i++)
		if(ch(pt, i)) DFS1(ch(pt, i)), sz[pt] += sz[ch(pt, i)];
	return;
}

inline void Push(int p, int q, int l, int r, int nm){
	for(int i = l-1; i >= 1; i--){
		int c = s1[i]-'a';
		assert(s1[i] == s2[i]);
		if(!ch(p, c))	break;
		p = ch(p, c);
	}
	for(int i = r+1; i <= m; i++){
		int c = s1[i]-'a';
		assert(s1[i] == s2[i]);
		if(!ch(q, c))	break;
		q = ch(q, c);
	}
	Q(p).push_back({q, nm});
	return;
}

inline void DFS2(int pt){
	for(int i : C(pt))	Add(dfn[i], 1), Add(dfn[i]+sz[i], -1);
	for(PR i : Q(pt))	ans[i.se] = Query(dfn[i.fi]);
	for(int i = 0; i < 26; i++)
		if(ch(pt, i)) DFS2(ch(pt, i));
	for(int i : C(pt))	Add(dfn[i], -1), Add(dfn[i]+sz[i], 1);
	return;
}

//-----

bool end_mem;

int main(){
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cerr<<abs((&end_mem)-(&begin_mem))/1024/1024<<endl;
	scanf("%d%d", &n, &q);
	for(int i = 1; i <= n; i++){
		scanf(" %s %s", s1+1, s2+1);
		m = strlen(s1+1);
		int l, r; Get(l, r);
		if(l > m)	continue;
		HS tmp = Calc(l, r);
		if(!mp1[tmp])	mp1[tmp] = ++tot, mp2[tmp] = ++tot;
		Insert(mp1[tmp], mp2[tmp], l, r);
	}
	for(auto i : mp2)	DFS1(i.se);
	cerr<<tot<<endl;
	for(int i = 1; i <= q; i++){
		scanf(" %s %s", s1+1, s2+1);
		m = strlen(s1+1);
		int qwq = strlen(s2+1);
		if(m != qwq)	continue;
		int l, r; Get(l, r);
		assert(l <= m);
		HS tmp = Calc(l, r);
		if(mp1.find(tmp) == mp1.end())	continue;
		Push(mp1[tmp], mp2[tmp], l, r, i);
	}
	for(auto i : mp1)	DFS2(i.se);
	for(int i = 1; i <= q; i++)	printf("%d\n", ans[i]);
	
	return 0;
}
/*
注意判断 t 长度是否相同 

感觉上像 AC 自动机题。
同时遍历两个 AC 自动机。
然后我们需要计数，当前这条 fail 链上面，有多少字符串来自同一个对。
不，这样不能直接解决这道题。
我们还需要保证别的位置 s,t 是相同的。
我们找到 t1,t2 的极小的不同子串。
并对所有的 s1,s2 也维护这个东西。可能没有。
很容易找到有哪些 s1,s2 是可能正确的。
现在的问题是维护这个极小子串前后，可能黏一段相同字符。需要比较 s,t 的该部分。
比较麻烦。因为直接枚举可能是 len^2 的。
似乎可以用 Trie 转化为二维数点？这下看懂了。

让我们来梳理一下思路：
1.	维护所有极小不同子串相同的等价类。对每个等价类建 2 棵 Trie
2.	每次在等价类中做访问。
然后我们还需要维护链上相同的对。。。
其实可以全部抽出来，因为我们可以一个一个访问 Trie。
但也不能完全吧？因为一个点可能意味着很多个 s。
我怎么感觉需要扫描线一下。。。
那就扫描线一下吧。 

注意 t1 != t2，我们并不需要特判 s1 == s2 的情况。 
*/