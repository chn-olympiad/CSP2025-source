#include<bits/stdc++.h>
using namespace std;
const long long N = 3e5 + 10;
struct node{
    int v, pos;
};
struct club{
    node a, b, c;
    int dc1, dc2;
}g[N];
int T, n;
bool cmp1(club a, club b) {
    return a.a.v > b.a.v;
}
bool cmp2(club a, club b) {
    return a.dc1 < b.dc1;
}
club xx[N], yy[N], zz[N];
int tot1, tot2, tot3;
signed main() {
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> T;
    while(T--) {
        tot1 = 0, tot2 = 0, tot3 = 0;
        memset(xx, 0, sizeof xx);
        memset(yy, 0, sizeof yy);
        memset(zz, 0, sizeof zz);
        cin >> n;
        for(int i = 1;i <= n; i++) {
            int a, b, c;
            cin >> a >> b >> c;
            node xx, yy, zz;
            if(max({a, b, c}) == a) {
                xx.v = a, xx.pos = 1;
                if(min(b, c) == b) zz.v = b, zz.pos = 2, yy.v = c, yy.pos = 3;
                else zz.v = c, zz.pos = 3, yy.v = b, yy.pos = 2;
            }
            if(max({a, b, c}) == b) {
                xx.v = b, xx.pos = 2;
                if(min(a, c) == a) zz.v = a, zz.pos = 1, yy.v = c, yy.pos = 3;
                else zz.v = c, zz.pos = 3, yy.v = a, yy.pos = 1;
            }
            if(max({a, b, c}) == c) {
                xx.v = c, xx.pos = 3;
                if(min(a, b) == a) zz.v = a, zz.pos = 1, yy.v = b, yy.pos = 2;
                else zz.v = b, zz.pos = 2, yy.v = a, yy.pos = 1;
            }
            g[i].a = xx, g[i].b = yy, g[i].c = zz, g[i].dc1 = xx.v - yy.v, g[i].dc2 = yy.v - zz.v;
        }
        sort(g + 1, g + n + 1, cmp1);
        for(int i = 1;i <= n; i++) {
           if(g[i].a.pos == 1) xx[++tot1] = g[i];
           if(g[i].a.pos == 2) yy[++tot2] = g[i];
           if(g[i].a.pos == 3) zz[++tot3] = g[i];
        }
        int sum = 0;
        for(int i = 1;i <= n; i++) {
            sum += g[i].a.v;
        }
        if(tot1 > (n / 2) || tot2 > (n / 2) || tot3 > (n / 2)) {
            if(tot1 > (n / 2)) {

                int cnt = tot1 - (n / 2);
                sort(xx + 1, xx + tot1 + 1, cmp2);
                for(int i = 1;i <= cnt; i++) {
                    sum -= xx[i].dc1;
                }
            }
            if(tot2 > (n / 2)) {
                //cout << 'y' << " ";
                int cnt = tot2 - (n / 2);
                sort(yy + 1, yy + tot2 + 1, cmp2);
                for(int i = 1;i <= cnt; i++) {
                    sum -= yy[i].dc1;
                }
            }
            if(tot3 > (n / 2)) {
                int cnt = tot3 - (n / 2);
                sort(zz + 1, zz + tot3 + 1, cmp2);
                for(int i = 1;i <= cnt; i++) {
                    sum -= zz[i].dc1;
                }
            }
        }
        cout << sum << '\n';
        continue;

    }
}
