#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
struct T {
    int a, b, c, d;
} tao[N];
int medi(int x, int y, int z) {
    int a = max(x, max(y, z));
    int b = min(x, min(y, z));
    if(x != a && x != b) return x;
    if(y != a && y != b) return y;
    if(z != a && z != b) return z;
    return 0;
}
int vis[N], a[N], b[N], c[N];
int main () {
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while(T--) {
        memset(tao, 0, sizeof(tao));
        memset(vis, 0, sizeof(vis));
        memset(a, 0, sizeof(a));
        memset(b, 0, sizeof(b));
        memset(c, 0, sizeof(c));
        int n, cnt=0, x=0, y=0, z=0;
        cin >> n;
        for(int i = 1; i <= n; i++) {
            cin >> tao[i].a >> tao[i].b >> tao[i].c;
            tao[i].d = i;
            int nf = max(tao[i].a, max(tao[i].b, tao[i].c));
            cnt += nf;
            if(nf == tao[i].a) {
                if(tao[i].a == tao[i].b || tao[i].a == tao[i].c) {
                    a[x] = 0;
                    x++;
                    continue;
                }
                a[x] = nf-medi(tao[i].a, tao[i].b, tao[i].c);
                x++;
            }
            else {
                if(nf == tao[i].b) {
                    if(tao[i].b == tao[i].c) {
                        b[y] = 0;
                        y++;
                        continue;
                    }
                    b[y] = nf-medi(tao[i].a, tao[i].b, tao[i].c);
                    y++;
                }
                else {
                    if(nf == tao[i].c) {
                        c[z] = nf-medi(tao[i].a, tao[i].b, tao[i].c);
                        z++;
                    }
                }
            }
        }
        sort(a, a+x);sort(b, b+y);sort(c, c+z);
        int k = n/2;
        if(x > k) {
            for(int i = 0; i < x-k; i++) {
                cnt-=a[i];
            }
        }
        if(y > k) {
            for(int i = 0; i < y-k; i++) {
                cnt-=b[i];
            }
        }
        if(z > k) {
            for(int i = 0; i < z-k; i++) {
                cnt-=c[i];
            }
        }
        cout << cnt << '\n';
    }
}