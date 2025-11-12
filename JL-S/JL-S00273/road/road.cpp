#include<bits/stdc++.h>
using namespace std;
const int N = 1e4+10;
const int M = 2e6+10;
struct T {
    int a, b, c;
} tao[M], tao1[M];
int a[12][N], minn = 0x3f3f3f3f;
int f[N];
int find(int a) {
    if(f[a] == a) return a;
    return f[a] = find(f[a]);
}
void add(int a, int b) {
    int x = find(a), y = find(b);
    f[x] = y;
}
bool cmp(T x, T y) {
    return x.c > y.c;
}
int main () {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    for(int i = 0; i < m; i++) {
        cin >> tao[i].a >> tao[i].b >> tao[i].c;
    }
    for(int i = 0; i < k; i++) {
        for(int j = 0; j <= n; j++) {
            cin >> a[i][j];
        }
    }
    for(int i = 0; i < pow(2,k); i++) {
        for(int i = 0; i < n+20; i++) {
            f[i] = i;
        }
        memcpy(tao1, tao, sizeof(tao));
        int cnt=0;
        int xa = 0;
        for(int j = 0; i < k; i++) {
            if((1<<j)&i) {
                for(int k = 0; k < n; k++) {
                    int x = m+xa*n-1;
                    tao1[x++].a = j+n-1, tao1[x].b = k, tao1[x].c = a[j][k];
                }
                cnt += a[j][0];
                xa++;
            }
        }
        sort(tao1, tao1+xa*n+m, cmp);
        for(int i = 0; i < xa*n+m; i++) {
            int xaa = find(tao[i].a), xbb = find(tao[i].b);
            if(xaa == xbb) continue;
            else add(xaa, xbb);
            cnt += tao[i].c;
        }
        minn = min(cnt, minn);
    }
    cout << minn;
}