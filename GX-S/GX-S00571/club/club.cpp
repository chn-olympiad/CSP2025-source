#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long LL;

const int MAX_N = 1e5+5;

int n, t[4];
LL ans;

struct Node_t {
    int a[4], b, mx, cmx;
}c[MAX_N];

bool cmp (Node_t x, Node_t y) {
    return x.cmx - x.mx > y.cmx - y.mx;
}

void run () {
    scanf("%d",&n);
    t[0] = t[1] = t[2] = t[3] = 0;
    ans = 0;
    for(int i = 1; i <= n; i ++) {
        c[i].a[1] = c[i].a[2] = c[i].a[3] = 0;
        c[i].b = 0;
        c[i].mx = c[i].cmx = -1;
    }
    for(int i = 1; i <= n; i ++) {
        scanf("%d%d%d",&c[i].a[1],&c[i].a[2],&c[i].a[3]);
        c[i].mx = max(c[i].a[1], max(c[i].a[2], c[i].a[3]));
        bool is_mx = false;
        if(c[i].a[1] == c[i].mx) {
            is_mx = true;
            c[i].b = 1;
            ++ t[1];
        }
        else c[i].cmx = max(c[i].cmx, c[i].a[1]);

        if(c[i].a[2] == c[i].mx && !is_mx) {
            is_mx = true;
            c[i].b = 2;
            ++ t[2];
        }
        else c[i].cmx = max(c[i].cmx, c[i].a[2]);

        if(c[i].a[3] == c[i].mx && !is_mx) {
            is_mx = true;
            c[i].b = 3;
            ++ t[3];
        }
        else c[i].cmx = max(c[i].cmx, c[i].a[3]);
    }
    if(t[1] <= n/2 && t[2] <= n/2 && t[3] <= n/2) {
        for(int i = 1; i <= n; i ++) {
            ans += c[i].mx;
        }
        printf("%lld\n",ans);
        return;
    }
    sort(c+1, c+1+n, cmp);
    int d;
    if(t[1] > n/2) d = 1;
    else if(t[2] > n/2) d = 2;
    else d = 3;
    for(int i = 1; i <= n; i ++) {
        if(c[i].b == d && t[d] > n/2) {
            ans += c[i].cmx;
            -- t[d];
        }
        else ans += c[i].mx;
    }
    printf("%lld\n",ans);
}

// can you give me 100 pts?

int main () {
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
   // freopen("club5.in","r",stdin);
    int T;
    scanf("%d",&T);
    while(T --) run();
    return 0;
}
