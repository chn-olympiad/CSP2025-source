#include <iostream>
#include <stdio.h>
#include <cstring>
#include <algorithm>
using namespace::std;
const int N = 1e5 + 10;
struct node {
    int maxn, secondd, minn;
    int a, b, c ;
    bool isused;
}a[N];
bool cmpa(node x, node y) {
    return x.maxn > y.maxn;
 }
 bool cmpb(node x, node y) {
    return x.secondd > y.secondd;
 }
 bool cmpc(node x, node y) {
    return x.minn > y.minn;
 }
int main(){
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    int T, n;
    scanf("%d", &T);
    while(T--) {
        memset(a, 0, sizeof(a));
        scanf("%d", &n);
        for(int i = 1; i <= n; i++) {
            scanf("%d%d%d", &a[i].a, &a[i].b, &a[i].c);
            a[i].maxn = max(a[i].a, max(a[i].b, a[i].c));
            a[i].minn = min(a[i].a, min(a[i].b, a[i].c));
            a[i].secondd = a[i].a + a[i].b + a[i].c - a[i].maxn - a[i].minn;
        }
        int pa = 0, pb = 0, pc = 0;
        long long ans = 0;
        sort(a + 1, a + n + 1, cmpa);
        for(int i = 1; i <= n; i++) {
            if(a[i].isused == 1) continue;
            if(a[i].a == a[i].maxn) {
                if(pa < n / 2) {
                    pa++;
                    a[i].isused = 1;
                    ans += a[i].a;
                    continue;
                }
            } else if(a[i].b == a[i].maxn) {
                if(pb < n / 2) {
                     pb++;
                     a[i].isused = 1;
                     ans += a[i].b;
                     continue;
                }
            } else if(a[i].c == a[i].maxn) {
                if(pc < n / 2) {
                    pc++;
                    a[i].isused = 1;
                    ans += a[i].c;
                    continue;
                }
            }
        }
        sort(a + 1, a + n + 1, cmpb);
        for(int i = 1; i <= n; i++) {
            if(a[i].isused == 1) continue;
            if(a[i].a == a[i].secondd) {
                if(pa < n / 2) {
                    pa++;
                    a[i].isused = 1;
                    ans += a[i].a;
                    continue;
                }
            } else if(a[i].b == a[i].secondd) {
                if(pb < n / 2) {
                     pb++;
                     a[i].isused = 1;
                     ans += a[i].b;
                     continue;
                }
            } else if(a[i].c == a[i].secondd) {
                if(pc < n / 2) {
                    pc++;
                    a[i].isused = 1;
                    ans += a[i].c;
                    continue;
                }
            }
        }
        sort(a + 1, a + n + 1, cmpc);
        for(int i = 1; i <= n; i++) {
            if(a[i].isused == 1) continue;
            if(a[i].a == a[i].minn) {
                if(pa < n / 2) {
                    pa++;
                    a[i].isused = 1;
                    ans += a[i].a;
                    continue;
                }
            } else if(a[i].b == a[i].minn) {
                if(pb < n / 2) {
                     pb++;
                     a[i].isused = 1;
                     ans += a[i].b;
                     continue;
                }
            } else if(a[i].c == a[i].minn) {
                if(pc < n / 2) {
                    pc++;
                    a[i].isused = 1;
                    ans += a[i].c;
                    continue;
                }
            }
        }
        printf("%lld\n", ans);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
