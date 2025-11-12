#include <cstdio>
#define isfileio 1
#define filename "road"
#define method 1
#if isfileio
#define programmefilein fopen(filename ".in", "r")
#define programmefileout fopen(filename ".out", "w")
#else
#define programmefilein stdin
#define programmefileout stdout
#endif
class fastInputHelper{
	char buf[1048577], *cn, *bufend;
	FILE *file;
	inline int getchar(){
		return cn != bufend ? *cn++ :
			(bufend = buf + fread(cn = buf, sizeof(char), 1048576llu, file), cn != bufend) ?
			*cn++ : ~0;
	}
	public:
		fastInputHelper(): cn(buf), bufend(buf), file(programmefilein){}
		~fastInputHelper(){
			fclose(file);
		}
		template<typename digit_type>
		fastInputHelper &operator>>(digit_type &x){
			int c = getchar();
			x = 0;
			while (c < 48 || c > 57){
				c = getchar();
				if (c == ~0){
					return *this;
				}
			}
			while (c > 47 && c < 58){
				x = x * 10 + (c & 15);
				c = getchar();
			}
			return *this;
		}
}fih;
class fastOutputHelper{
	char buf[1048577], *cn;
	const char *bufend;
	FILE *file;
	inline void putchar(int c){
		*cn++ = c;
		if (cn == bufend){
			fwrite(cn = buf, sizeof(char), 1048576llu, file);
		}
	}
	template<typename digit_type>
	void writedigit(const digit_type &x){
		if (x){
			writedigit(x / 10);
			putchar(x % 10 | 48);
		}
	}
	public:
		fastOutputHelper(): cn(buf), bufend(buf + 1048576llu), file(programmefileout){}
		~fastOutputHelper(){
			if (cn != buf){
				fwrite(buf, sizeof(char), cn - buf, file);
				cn = buf;
			}
			fclose(file);
		}
		template<typename digit_type>
		fastOutputHelper &operator<<(const digit_type &x){
			if (x > 0){
				writedigit(x / 10);
				putchar(x % 10 | 48);
			}
			else if(x == 0){
				putchar(48);
			}
			else{
				putchar('-');
				writedigit(-(x / 10));
				putchar(-(x % 10) | 48);
			}
			return *this;
		}
		inline fastOutputHelper &putc(int c){
			putchar(c);
		}
}foh;
#if method == 1
#include <algorithm>
#include <array>
#include <utility>
#include <vector>
#define find(x) while (x ^ fa[x]) x = fa[x] = fa[fa[x]]
std::vector<std::pair<int, int>> to[10001];
std::array<int, 3> edge[1000001];
int c[10][10001], mx[40001], fa[10001], size[10001], depth[10001], heavy[10001], dfn[10001], top[10001];
unsigned long long cost;
int n, m, k, dfnnum;
inline int max(int a, int b){
	return a > b ? a : b;
}
void dfs1(int root){
	int newdepth = depth[root] + 1, j = 0;
	size[1] = root;
	for (const std::pair<int, int> &p : to[root]){
		int ch = p.first;
		if (!depth[ch]){
			depth[ch] = newdepth;
			fa[ch] = root;
			dfs1(ch);
			size[root] += size[ch];
			if (size[ch] > size[j]){
				j = ch;
			}
		}
	}
	heavy[root] = j;
}
void dfs2(int root, int an){
	dfn[root] = ++dfnnum;
	top[root] = an;
	if (heavy[root]){
		int i = fa[root], j = heavy[root];
		dfs2(j, an);
		for (const std::pair<int, int> &p : to[root]){
			int ch = p.first;
			if (ch ^ i){
				if (ch ^ j){
					dfs2(ch, ch);
				}
				edge[dfn[ch]][0] = p.second;
			}
		}
	}
}
void build(int l, int r, int i){
	if (l + 1 == r){
		mx[i] = edge[l][0];
		return;
	}
	int m = l + r >> 1, li = i << 1, ri = li | 1;
	build(l, m, li);
	build(m, r, ri);
	mx[i] = max(mx[li], mx[ri]);
}
int lca(int u, int v, int &mx){
	return 0;
}
int main(){
	fih >> n >> m >> k;
	for (int i = n; i; --i){
		fa[i] = i;
	}
	for (int i = 0; i < m; ++i){
		fih >> edge[i][1] >> edge[i][2] >> edge[i][0];
	}
	for (int i = 0; i < k; ++i){
		for (int j = 0; j <= n; ++j){
			fih >> c[i][j];
		}
	}
	std::sort(edge, edge + m);
	for (int i = 0, r = n - 1; r; ++i){
		int u = edge[i][1], v = edge[i][2];
		find(u);
		find(v);
		if (u ^ v){
			--r;
			fa[u] = v;
			to[u].emplace_back(v, edge[i][0]);
			to[v].emplace_back(u, edge[i][0]);
			cost += edge[i][0];
		}
	}
	fa[1] = 0;
	depth[1] = 1;
	edge[1][0] = 0;
	dfs1(1);
	dfs2(1, 1);
	build(1, n + 1, 1);
	foh << cost;
	return 0;
}
#undef find
#endif
