#include <bits/stdc++.h>

#define int long long

using namespace std;

int n, m, k;
int cnt = 0;
int c[11];
int fa[1000010];
int sta[1000010];
int ans[1000010];
int tot = 0;

struct node {
    int u, v, w;
}line[1000010], a[2000010];

inline int read() {
    int x = 0, f = 1;
    char ch = getchar();
    while(ch < '0' || ch > '9') {
        if(ch == '-')
            f = -1;
        ch = getchar();
    }
    while(ch >= '0' && ch <= '9') {
        x = (x << 1) + (x << 3) + (ch ^ 48);
        ch = getchar();
    }
    return x * f;
}

inline void write(int x) {
    if(x < 0) {
        putchar('-');
        x = -x;
    }
    if(x > 9)
        write(x / 10);
    putchar(x % 10 + '0');
}

inline void writeln(int x) {
    write(x);
    putchar('\n');
}

inline int find(int p) {
    if(fa[fa[p]] != fa[p]) {
        fa[p] = find(fa[p]);
    }
    return fa[p];
}

inline void merge(int p, int q) {
    fa[fa[p]] = fa[q];
}

inline bool cmp(node x, node y) {
    return x.w < y.w;
}

inline int solve() {
    int kk = 0;
    for(int i = n + 1; i <= n + k; ++i) {
        if(sta[i]) {
            ++kk;
        }
    }
    // writeln(kk);
    for(int i = 1; i <= n + k; ++i) {
        fa[i] = i;
    }
    int noww = 0;
    int ret = 0;
    for(int i = 1; i <= tot; ++i) {
        int u = a[i].u;
        int v = a[i].v;
		if(u > n && !sta[u]) continue;
        if(find(u) != find(v)) {
            fa[find(u)] = find(v);
            ret += a[i].w;
            ++noww;
            // cout << u << ' ' << v << ' ' << a[i].w << endl;
        }
        if(noww == n + kk - 1) {
            break;
        }
    }
    // writeln(noww);
    return ret;
}

signed main() {
	
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);

    n = read();
    m = read();
    k = read();

    for(int i = 1; i <= m; ++i) {
        int u, v, w;
        u = read();
        v = read();
        w = read();
        line[++cnt] = {u, v, w};
    }
    
    for(int i = 1; i <= n + k; ++i) {
        fa[i] = i;
    }

    sort(line + 1, line + cnt + 1, cmp);

    for(int i = 1; i <= m; ++i) {
        int u = line[i].u;
        int v = line[i].v;
        // int w = line[i].w;
        if(find(u) != find(v)) {
            merge(u, v);
            a[++tot] = line[i];
            // cout << u << ' ' << v << endl;
        }
        if(tot == n - 1) {
            break;
        }
    }

    for(int i = 1; i <= k; ++i) {
        c[i] = read();
        for(int j = 1; j <= n; ++j) {
            int tmp = read();
            a[++tot] = {i + n, j, tmp};
        }
    }

    sort(a + 1, a + tot + 1, cmp);
    
    //for(int i = 1; i <= tot; ++i) {
		//cout << a[i].u << ' ' << a[i].v << ' ' << a[i].w << endl;
	//}
    
    // writeln(tot);
    
    for(int i = 1; i <= n; ++i) {
		sta[i] = 1;
	}

    for(int i = 0; i <= (1 << k) - 1; ++i) {
        for(int j = 1; j <= k; ++j) {
            sta[j + n] = ((i >> (j - 1)) & 1);
            if(sta[j + n])
                ans[i] += c[j];
        }
        //for(int j = 1; j <= k; ++j) {
        //    cout << sta[j + n] << ' ';
        //}
        //cout << endl;
        //cout << ans[i] << endl;
        ans[i] += solve();
    }

    int maxxx = 0x3f3f3f3f3f3f3f3f;

    for(int i = 0; i <= (1 << k) - 1; ++i) {
        maxxx = min(maxxx, ans[i]);
    }

    writeln(maxxx);

    return 0;
}
