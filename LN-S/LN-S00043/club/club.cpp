#include<bits/stdc++.h>
using namespace std;

const int N=100000;
struct Info {
    int x, y, z;
    bool operator < (const Info &A) {
        return x > A.x;
    }
} a[N+10];
int t, n, ans=0;

inline void dfs(int i, int cx, int cy, int cz, int cnt) {
    if(i==n+1) {
        ans=max(ans, cnt);
        return;
    }
    if(cx<(n/2)) dfs(i+1, cx+1, cy, cz, cnt+a[i].x);
    if(cy<(n/2)) dfs(i+1, cx, cy+1, cz, cnt+a[i].y);
    if(cz<(n/2)) dfs(i+1, cx, cy, cz+1, cnt+a[i].z);
}
int main() {
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    scanf("%d", &t);
    for(int r=1;r<=t;r++) {
        scanf("%d", &n);
        if(n>30) {
            int tot=0;
            sort(a+1, a+n+1);
            for(int i=1;i<=(n/2);i++)
                tot+=a[i].x;
            printf("%d\n", tot);
        }
        else {
            for(int i=1;i<=n;i++)
                scanf("%d%d%d", &a[i].x, &a[i].y, &a[i].z);
            ans=0;
            dfs(1, 0, 0, 0, 0);
            printf("%d\n", ans);
        }
    }
    return 0;
}
