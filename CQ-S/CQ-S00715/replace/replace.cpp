#include<bits/stdc++.h>
using namespace std;
const int N = 200005, M = 2000005;
namespace cza{
	int n, q;
	char a[M], b[M];
	int pos1[N], pos2[N];
	vector<int> ve[2][M];
	struct node{
		int ch[26], fail, dep;
	};
	int fa[2][24][M];
	struct AC_Trie{
		node t[M];
		int tcnt = 1;
		int upd(char *a){
			int len = strlen(a + 1);
			int now = 1;
//			cout << "???" << len << '\n';
			for(int i = 1; i <= len; i++){
				int &v = t[now]. ch[a[i] - 'a'];
				if(!v) v = ++tcnt, t[v]. dep = t[now]. dep + 1;
				now = v;
//				cout << now << '\n';
			}
			return now;
		}
		
		queue<int> q;
		void build(int id){
			t[1]. fail = 0;
			for(int j = 0; j < 26; j++){
				t[0]. ch[j] = 1;
			}
			q. push(1);
			while(!q. empty()){
				int u = q. front();
				q. pop();
				for(int j = 0; j < 26; j++){
					int &v = t[u]. ch[j];
					if(!v){
						v = t[t[u]. fail]. ch[j];
					}else{
						t[v]. fail = t[t[u]. fail]. ch[j];
						q. push(v);
					}
				}
			}
			for(int i = 2; i <= tcnt; i++){
//				cout << i << ' ' << t[i]. fail << '\n';
				ve[id][t[i]. fail]. push_back(i);
				fa[id][0][i] = t[i]. fail;
			}
		}
	}ac1, ac2;
	int dfn[M], ed[M], dfn2[M], ed2[M];
	vector<pair<int, pair<int, int> > > qu[M];
	vector<int> ids[M];
	long long ans[N];
	void dfs1(int u){
		dfn[u] = ++dfn[0];
		for(int j = 1; j <= 23; j++){
			fa[0][j][u] = fa[0][j - 1][fa[0][j - 1][u]];
		}
		for(int v : ve[0][u]){
			dfs1(v);
		}
		ed[u] = dfn[0];
	}
	void dfs2(int u){
		dfn2[u] = ++dfn2[0];
		for(int j = 1; j <= 23; j++){
			fa[1][j][u] = fa[1][j - 1][fa[1][j - 1][u]];
		}
		for(int v : ve[1][u]){
			dfs2(v);
		}
		ed2[u] = dfn2[0];
	}
	void init(){
		dfs1(1);
		dfs2(1);
		for(int i = 1; i <= n; i++){
			ids[pos1[i]]. push_back(pos2[i]);
		}
	}
	struct BIT{
		int t[M];
		void upd(int u, int v){
			while(u <= dfn2[0]){
				t[u] += v;
				u += u & -u;
			}
		}
		int find(int u){
			int ret = 0;
			while(u){
				ret += t[u];
				u -= u & -u;
			}
			return ret;
		}
	}t1;
	struct BIT2{
		int t[M];
		void upd(int u, int v){
			while(u){
				t[u] += v;
				u -= u & -u;
			}
		}
		int find(int u){
			int ret = 0;
			while(u <= dfn2[0]){
				ret += t[u];
				u += u & -u;
			}
			return ret;
		}
	}t2;
	int cc = 0;
	void solve(int u){
		for(int v : ids[u]){
			cc++;
			t1. upd(ed2[v], 1);
			t2. upd(dfn2[v], 1);
		}
		
		for(pair<int, pair<int, int> > qq : qu[u]){
			int v = cc - t1. find(dfn2[qq. first] - 1) - t2. find(dfn2[qq. first] + 1);
			ans[qq. second. first] += v * qq. second. second;
		}
		
		for(int v : ve[0][u]){
			solve(v);
		}
		
		for(int v : ids[u]){
			cc--;
			t1. upd(ed2[v], -1);
			t2. upd(dfn2[v], -1);
		}
	}
	int get_fa1(int u, int len){
		if(ac1. t[u]. dep < len) return u;
		for(int i = 23; i >= 0; i--){
			if(fa[0][i][u] and ac1. t[fa[0][i][u]]. dep >= len) u = fa[0][i][u];
		}
		return fa[0][0][u];
	}
	int get_fa2(int u, int len){
		if(ac2. t[u]. dep < len) return u;
		for(int i = 23; i >= 0; i--){
			if(fa[1][i][u] and ac2. t[fa[1][i][u]]. dep >= len) u = fa[1][i][u];
		}
		return fa[1][0][u];
	}
	int main(){
		freopen("replace.in", "r", stdin);
		freopen("replace.out", "w", stdout);
		ios::sync_with_stdio(0), cin. tie(0), cout. tie(0);
		cin >> n >> q;
		for(int i = 1; i <= n; i++){
			cin >> (a + 1);
			pos1[i] = ac1. upd(a);
			cin >> (a + 1);
			pos2[i] = ac2. upd(a);
		}
		ac1. build(0), ac2. build(1);
		init();
		for(int i = 1; i <= q; i++){
			cin >> (a + 1) >> (b + 1);
			int len1 = strlen(a + 1), len2 = strlen(b + 1);
			if(len1 != len2){
				continue;
			}
			int ll = 1, rr = len1;
			while(ll <= len1 and a[ll] == b[ll]) ll++;
			while(rr and a[rr] == b[rr]) rr--;
			if(ll == len1 + 1){
				int now1 = 1, now2 = 1;
				for(int j = 1; j <= len1; j++){
					now1 = ac1. t[now1]. ch[a[j] - 'a'];
					now2 = ac2. t[now2]. ch[b[j] - 'a'];
					qu[now1]. push_back({now2, {i, 1}});
				}
			}else{
				int now1 = 1, now2 = 1;
				for(int j = 1; j <= len1; j++){
					now1 = ac1. t[now1]. ch[a[j] - 'a'];
					now2 = ac2. t[now2]. ch[b[j] - 'a'];
					if(j >= rr){
						int uu = get_fa1(now1, j - ll + 1), vv = get_fa2(now2, j - ll + 1);
						qu[now1]. push_back({now2, {i, 1}});
						qu[now1]. push_back({vv, {i, -1}});
						qu[uu]. push_back({now2, {i, -1}});
						qu[uu]. push_back({vv, {i, 1}});
					}
				}
			}
		}
		cc = 0;
		solve(1);
		for(int i = 1; i <= q; i++){
			cout << ans[i] << '\n';
		}
		return 0;	
	}
}
signed main(){
	return cza::main();
}
/*
log 但是常数又大又小 
*/
