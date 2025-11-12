#include<bits/stdc++.h>
using namespace std;
#define int long long
int T, n;
struct Aschuy {
    int a, b, c;
    bool flag;
} a[100010];
int findd(int xx, int y, int z) {
    if(xx>=y&&xx>=z) return xx-max(y, z);
    else if(y>=xx&&y>=z) return y-max(xx, z);
    else return z-max(xx, y);
}
bool cmp(Aschuy u, Aschuy v) {
    if(findd(u.a, u.b, u.c)!=findd(v.a, v.b, v.c)) return findd(u.a, u.b, u.c)>findd(v.a, v.b, v.c);
    else return max(max(u.a, u.b), u.c)>max(max(v.a, v.b), v.c);
}
signed main() {
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    cin >> T;
    while(T--) {
        cin >> n;
        if(n==2) {
            cin >> a[1].a >> a[1].b >> a[1].c >> a[2].a >> a[2].b >> a[2].c;
            cout << max(max(max(max(max(a[1].a+a[2].b, a[1].a+a[2].c), a[1].b+a[2].a), a[1].b+a[2].c), a[1].c+a[2].a), a[1].c+a[2].b) <<'\n';
            continue;
        }
        int cnta = 0, cntb = 0, cntc = 0, ans = 0, ben = n/2;
        for(int i = 1; i <= n; i++) {
            cin >> a[i].a >> a[i].b >> a[i].c;
            a[i].flag = 0;
        }
        sort(a+1, a+n+1, cmp);
        for(int cnter = 1; cnter<=3; cnter++) {
            for(int i = 1; i <= n; i++) {
                if(a[i].a>=a[i].b&&a[i].a>=a[i].c&&!a[i].flag) {
                    if(cnta<ben) {
                        cnta++;
                        ans+=a[i].a;
                        a[i].flag = 1;
                    }
                    else a[i].a = 0;
                }
                else if(a[i].b>=a[i].a&&a[i].b>=a[i].c&&!a[i].flag) {
                    if(cntb<ben) {
                        cntb++;
                        ans+=a[i].b;
                        a[i].flag = 1;
                    }
                    else a[i].b = 0;
                }
                else if(a[i].c>=a[i].a&&a[i].c>=a[i].b&&!a[i].flag) {
                    if(cntc<ben) {
                        cntc++;
                        ans+=a[i].c;
                        a[i].flag = 1;
                    }
                    else a[i].c = 0;
                }
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
