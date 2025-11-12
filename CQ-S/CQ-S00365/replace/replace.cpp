#include<bits/stdc++.h>
using namespace std;
const int N = 4e5 + 10, P = 5e6 + 10, M = 26 + 3, mod1 = 1e9 + 7, mod2 = 1e9 + 9, seed1 = 998244353, seed2 = 233;
struct node{
	int l, r, id, len, cnt, su1, su2, su3, su4;
}a[N];
struct node2{
	int son[M];
	inline void init(){
		for(int i = 0;i < 26;i = -~i) son[i] = 0;
		return ;
	}
}b[P], c[P];
int n, q, tot, cnt, cnt1, cnt2, su[P], in[P], ou[P], to[N], ne[N], id[N], ans[N], head[P];
string s[N][2];
inline void modify(int x, int y){
	for(;x <= cnt;x += x & (-x)) su[x] += y;
	return ;
}
inline int getsum(int x){
	int ans = 0;
	for(;x > 0;x -= x & (-x)) ans += su[x];
	return ans;
}
inline void solve(int id, string &x, string &y){
	a[++tot].id = id, a[tot].len = x.length();
	while(x[a[tot].l] == y[a[tot].l]) a[tot].l ++;
	while(x[a[tot].len - 1 - a[tot].r] == y[a[tot].len - 1 - a[tot].r]) a[tot].r ++;
	a[tot].cnt = a[tot].len - a[tot].l - a[tot].r;
	for(int i = a[tot].l;i <= a[tot].len - 1 - a[tot].r;i = -~i){
		int sux = x[i] - 'a', suy = y[i] - 'a';
		a[tot].su1 = (1ll * a[tot].su1 * seed1 + sux) % mod1, a[tot].su2 = (1ll * a[tot].su2 * seed2 + sux) % mod2;
		a[tot].su3 = (1ll * a[tot].su3 * seed1 + suy) % mod1, a[tot].su4 = (1ll * a[tot].su4 * seed2 + suy) % mod2;
	}
	return ;
}
inline bool cmp(node u, node v){
	if(u.cnt != v.cnt) return u.cnt < v.cnt;
	if(u.su1 != v.su1) return u.su1 < v.su1;
	if(u.su2 != v.su2) return u.su2 < v.su2;
	if(u.su3 != v.su3) return u.su3 < v.su3;
	return u.su4 < v.su4;
}
inline void dfs1(int x){
	for(int i = head[x], j;i != -1;i = ne[i]) if(a[to[i]].id <= n) j = id[to[i]], modify(in[j], 1), modify(ou[j] + 1, -1);
	for(int i = head[x];i != -1;i = ne[i]) if(a[to[i]].id > n) ans[a[to[i]].id - n] = getsum(in[id[to[i]]]);
	for(int i = 0;i < 26;i = -~i) if(b[x].son[i]) dfs1(b[x].son[i]);
	for(int i = head[x], j;i != -1;i = ne[i]) if(a[to[i]].id <= n) j = id[to[i]], modify(in[j], -1), modify(ou[j] + 1, 1);
	return ;
}
inline void dfs2(int x){
	in[x] = ++cnt, su[cnt] = 0;
	for(int i = 0;i < 26;i = -~i) if(c[x].son[i]) dfs2(c[x].son[i]);
	ou[x] = cnt;
	return ;
}
inline void getans(int x, int y){
	bool flag1 = false, flag2 = false;
	for(int i = x;i <= y;i = -~i){
		if(a[i].id <= n) flag1 = true;
		else flag2 = true;
	}
	if(!flag1 || !flag2) return ;
	head[0] = -1, cnt = cnt1 = cnt2 = 0, b[0].init(), c[0].init();
	for(int i = x;i <= y;i = -~i){
		int now = 0;
		for(int j = a[i].l - 1;j >= 0;j = ~-j){
			int v = s[a[i].id][0][j] - 'a';
			if(!b[now].son[v]) b[now].son[v] = ++cnt1, head[cnt1] = -1, b[cnt1].init();
			now = b[now].son[v];
		}
		ne[++cnt] = head[now], head[now] = cnt, to[cnt] = i, now = 0;
		for(int j = a[i].len - a[i].r;j < a[i].len;j = -~j){
			int v = s[a[i].id][0][j] - 'a';
			if(!c[now].son[v]) c[now].son[v] = ++cnt2, c[cnt2].init();
			now = c[now].son[v];
		}
		id[i] = now;
	}
	cnt = 0, dfs2(0), dfs1(0);
	return ;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin>>n>>q;
	for(int i = 1;i <= n;i = -~i){
		cin>>s[i][0]>>s[i][1];
		if(s[i][0] != s[i][1]) solve(i, s[i][0], s[i][1]);
	}
	for(int i = n + 1;i <= n + q;i = -~i){
		cin>>s[i][0]>>s[i][1];
		if(s[i][0].length() == s[i][1].length()) solve(i, s[i][0], s[i][1]);
	}
	sort(a + 1, a + 1 + tot, cmp);
	for(int i = 1, j = 1;i <= tot;){
		while(j != tot && a[j].cnt == a[j + 1].cnt && a[j].su1 == a[j + 1].su1 && a[j].su2 == a[j + 1].su2 && a[j].su3 == a[j + 1].su3 && a[j].su4 == a[j + 1].su4) j ++;
		getans(i, j), j ++, i = j;
	}
	for(int i = 1;i <= q;i = -~i) cout<<ans[i]<<'\n';
	return 0;
}
