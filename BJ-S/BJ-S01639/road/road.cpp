#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
long long n, m, k, fa[20005], c[15], a[15][10005], minn = 0x7f7f7f7f;
struct Node{
    long long u, v, w;
} r[2000005], rr[2000005];
bool cmp(Node x, Node y){
    return x.w < y.w;
}
long long myfind(long long x){
    if (fa[x] == x)
        return x;
    return fa[x] = myfind(fa[x]);
}
long long mintree(long long tom){
    for (long long i = 1; i <= n + k; i ++)
        fa[i] = i;
    for (long long i = 1; i <= m + tom * n; i ++)
        rr[i].u = r[i].u, rr[i].v = r[i].v, rr[i].w = r[i].w;
    sort(rr + 1, rr + m + tom * n + 1, cmp);
    long long ans = 0, cnt = 0;
    for (long long i = 1; i <= m + tom * n; i ++){
        long long x = rr[i].u, y = rr[i].v;
        if (myfind(x) == myfind(y))
            continue;
        //cout << x << " " << y << " fa: " << myfind(y) << " " << myfind(x) << endl;
        fa[myfind(y)] = myfind(x);
        ans += rr[i].w, cnt ++;
    }
    if (cnt != n + tom - 1) return 0x7f7f7f7f;
    else return ans;
}
void dfs(long long step, long long tom, long long sums){
    if (step == k + 1){
        //cout << "tom: " << tom << endl;
        long long ans = mintree(tom) + sums;
        //for (long long i = 1; i <= m + tom * n; i ++)
        //    cout << r[i].u << " " << r[i].v << " " << r[i].w << endl;
        minn = min(minn, ans);
        //cout << "ans: " << ans << endl;
        return ;
    }
    dfs(step + 1, tom, sums);
    long long d = m + tom * n;
    for (long long i = 1; i <= n; i ++)
        r[d + i].u = n + tom + 1, r[d + i].v = i, r[d + i].w = a[step][i];
    dfs(step + 1, tom + 1, sums + c[step]);
    return ;
}
int main(){
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    scanf("%lld%lld%lld", &n, &m, &k);
    for (long long i = 1; i <= m; i ++)
        scanf("%lld%lld%lld", &r[i].u, &r[i].v, &r[i].w);
    long long cnt = 0;
    for (long long i = 1; i <= k; i ++){
        scanf("%lld", &c[i]);
        cnt += c[i];
        for (long long j = 1; j <= n; j ++){
            scanf("%lld", &a[i][j]);
            cnt += a[i][j];
        }
    }
    if (cnt == 0){
        cout << 0 << endl;
        return 0;
    }
    dfs(1, 0, 0);
    cout << minn << endl;
    return 0;
}
