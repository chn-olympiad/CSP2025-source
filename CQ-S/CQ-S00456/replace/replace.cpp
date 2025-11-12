#include<cstdio>
#include<cstring>
#include<iostream>
#include<cmath>
typedef long long ll;
using namespace std;
namespace furina{
	const int N = 2e5, L = 5e6, inf = 0x7fffffff >> 1;
	
	string s, t;
	
	struct sam{
		int len, fa, ch[26];
		#define fa(u) tree[u].fa
		#define ch(u, c) tree[u].ch[c]
	} tree[(L << 1) + 10];
	int cnt = 1;
	
	inline int ins(int v, int c){
		int end;
		if(!ch(v, c)){
			int u = end = ++cnt;
			tree[u].len = tree[v].len + 1;
			for(; v && !ch(v, c); v = fa(v))
				ch(v, c) = u;
			if(!v)
				fa(u) = 1;
			else{
				int w1 = ch(v, c);
				if(tree[w1].len == tree[v].len + 1)
					fa(u) = w1;
				else{
					int w2 = ++cnt;
					tree[w2] = tree[w1];
					tree[w2].len = tree[v].len + 1;
					fa(u) = fa(w1) = w2;
					for(; v && ch(v, c) == w1; v = fa(v))
						ch(v, c) = w2;
				}
			}
		}
		else{
			int w1 = ch(v, c);
			if(tree[w1].len == tree[v].len + 1)
				end = w1;
			else{
				int w2 = ++cnt;
				tree[w2] = tree[w1];
				tree[w2].len = tree[v].len + 1;
				end = fa(w1) = w2;
				for(; v && ch(v, c) == w1; v = fa(v))
					ch(v, c) = w2;
			}
		}
		return end;
	}
	
	struct edge{
		int nxt, to;
	} e[(L << 1) + 10];
	int head[(L << 1) + 10], cntedge;
	int f[(L << 1) + 10];
	inline void addedge(int u, int v){
		e[++cntedge] = {head[u], v};
		head[u] = cntedge;
	}
	
	int que[(L << 1) + 10], ql, qr;
	inline void bfs(int s){
		ql = qr = 0;
		que[qr++] = s;
		while(ql < qr){
			int u = que[ql++];
			for(int i = head[u]; i; i = e[i].nxt){
				f[e[i].to] += f[u];
				que[qr++] = e[i].to;
			}
		}
	}
	
	int n, q, B;
	int ans[N + 10];
	char a[L + 10], b[L + 10], c[L + 10];
	
	struct node{
		int len, op, id, lst;
	} fnn[(L << 2) + N + 10];
	int zzm;
	int now[(L << 1) + 10];
	
	inline void update(int l, int r, int type, int id){
		int u = 1, len = 0;
		for(int i = l; i <= r; i++){
			int val = c[i] - 'a';
			while(u != 1 && !ch(u, val))
				len = tree[u = fa(u)].len;
			if(ch(u, val))
				u = ch(u, val), len++;
			if(!(i & 1)){
				ans[id] += type * f[fa(u)];
				fnn[++zzm] = {len, type, id, now[u]}, now[u] = zzm;
			}
		}
	}
	
	int lower[L + 10];
	int sk[N + 10], zk[N + 10], belong[N + 10];
	
	inline int read(){
		int x = 0;
		char ch = getchar();
		while(!isdigit(ch))
			ch = getchar();
		while(isdigit(ch)){
			x = (x << 1) + (x << 3) + ch - '0';
			ch = getchar();
		}
		return x;
	}
	
	inline int read(char *a){
		int len = 0;
		char ch = getchar();
		while(ch < 'a' || ch > 'z')
			ch = getchar();
		while(ch >= 'a' && ch <= 'z')
			a[++len] = ch, ch = getchar();
		return len;
	}
	
	inline int read(string &a){
		a = " ";
		int len = 0;
		char ch = getchar();
		while(ch < 'a' || ch > 'z')
			ch = getchar();
		while(ch >= 'a' && ch <= 'z')
			a += ch, ch = getchar(), len++;
		return len;
	}
	
	int main(){
		n = read(), q = read(), B = sqrt(n) + 1;
		
		for(int i = 1; i <= n; i++){//0.58
			int len = read(s);
			read(t);
			int lst = 1;
			for(int j = 1; j <= len; j++){
				lst = ins(lst, s[j] - 'a');
				lst = ins(lst, t[j] - 'a');
			}
			f[lst]++, fnn[++zzm] = {len << 1, 0, 0, now[lst]}, now[lst] = zzm;
			lower[len << 1] = 1;
		}
		
		for(int i = 1, rk = 0; i <= L; i++){
			if(!lower[i])
				lower[i] = rk;
			else
				lower[i] = ++rk;
		}
		for(int i = 1; i <= n; i++)
			belong[i] = (i - 1) / B + 1;
		
		for(int i = 2; i <= cnt; i++)
			addedge(fa(i), i);
		bfs(1);//0.1
		
		for(int i = 1; i <= q; i++){//0.1
			int len = read(a), lenb = read(b);
			if(lenb != len)
				continue;
			int L = -1, R = -1;
			for(int j = 1; j <= len; j++){
				c[(j << 1) - 1] = a[j], c[j << 1] = b[j];
				if(a[j] != b[j]){
					R = j;
					if(L == -1)
						L = j;
				}
			}
			len <<= 1;
			update(1, len, 1, i);
			if(L != -1){
				update((L << 1) + 1, len, -1, i);
				update(1, (R << 1) - 2, -1, i);
				update((L << 1) + 1, (R << 1) - 2, 1, i);
			}
		}
		
		for(int i = 1; i <= cnt; i++){//0.1s
			for(int u = now[i]; u; u = fnn[u].lst){
				if(!fnn[u].id){
					int h = lower[fnn[u].len];
					int bl = belong[h];
					for(int j = bl; j <= belong[n]; j++)
						zk[j]++;
					for(int j = h; j <= bl * B; j++)
						sk[j]++;
				}
			}
			for(int u = now[i]; u; u = fnn[u].lst){
				if(fnn[u].id){
					int h = lower[fnn[u].len];
					int bl = belong[h], res = 0;
					for(int j = 1; j < bl; j++)
						res += zk[j];
					for(int j = (bl - 1) * B + 1; j <= h; j++)
						res += sk[j];
					ans[fnn[u].id] += fnn[u].op * res;
				}
			}
			for(int u = now[i]; u; u = fnn[u].lst){
				if(!fnn[u].id){
					int h = lower[fnn[u].len];
					int bl = belong[h];
					for(int j = bl; j <= belong[n]; j++)
						zk[j]--;
					for(int j = h; j <= bl * B; j++)
						sk[j]--;
				}
			}
		}
		
		for(int i = 1; i <= q; i++)
			cout << ans[i] << '\n';
		return 0;
	}
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	furina::main();
//	while(1);
	return 0;
}
