#include<bits/stdc++.h>

using namespace std;

int t;
int n;
struct E{
    int a, b, c;
    bool operator < (const E &A){
        if(A.a != a) return a > A.a;
        else if(A.b != b) return b > A.b;
        else return c > A.c;
    }
}a[100001];
bool cmp(const E &x, const E &y){
    return x.a > y.a;
}

long long ans;

inline void dfs(int i, int na, int nb, int nc, long long cnt){
    if(i == n + 1){
        ans = max(ans, cnt);
        return;
    }
    if(na < n / 2) dfs(i + 1, na + 1, nb, nc, cnt + a[i].a);
    if(nb < n / 2) dfs(i + 1, na, nb + 1, nc, cnt + a[i].b);
    if(nc < n / 2) dfs(i + 1, na, nb, nc + 1, cnt + a[i].c);
}

int main(){
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    scanf("%d", &t);
    for(; t--; ){
        ans = -1;
        scanf("%d", &n);
        for(int i = 1; i <= n; i++)
            scanf("%d%d%d", &a[i].a, &a[i].b, &a[i].c);
        bool f = 0;
        for(int i = 1; i <= n && !f; i++)
            if(a[i].b != 0 || a[i].c != 0)
                f = 1;
        if(!f){
            sort(a + 1, a + n + 1, cmp);
            for(int i = 1; i <= n / 2; i++)
                ans += a[i].a;
            printf("%lld", ans);
            return 0;
        }
        dfs(1, 0, 0, 0, 0);
        printf("%lld\n", ans);
    }
    return 0;
}
