#include<bits/stdc++.h>
using namespace std;
int n, m, k, p[15], mxf, fa[10015];
struct edge{
    int x, y, val;
} a[1100006], b[1100006];
bool f[10015], v[10015];
bool cmp(edge x, edge y){
    return x.val < y.val;
}int findfa(int x){
    //printf("%d\n", x);
    return (x == fa[x]) ? x : (fa[x] = findfa(fa[x]));
}long long solve(){
    int cnt = m, ans = 0;
    for(int i = 1; i <= m; i++) b[i] = a[i];
    for(int i = 1; i <= k; i++){
        if(f[i + n]) continue;
        for(int j = 1; j <= n; j++) b[++cnt] = a[m + (i - 1) * n + j];
    }// printf("%d\n", cnt);
    for(int i = 1; i <= n + k; i++) fa[i] = i;
    sort(b + 1, b +1 + cnt, cmp);
    for(int i = 1; i <= cnt; i++){
        if(findfa(b[i].x) != findfa(b[i].y)){
            //printf("%d %d %d\n", b[i].x, b[i].y, b[i].val);
            fa[findfa(b[i].x)] = b[i].y;
            ans += b[i].val;
        }
    }// printf("%d\n", ans);
    return ans;
}
int main(){
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    long long ans = 1E17;
    scanf("%d%d%d", &n, &m, &k);
    for(int i = 1; i <= m; i++){
        scanf("%d%d%d", &a[i].x, &a[i].y, &a[i].val);
    }//sort(a +1, a +1 + m, cmp);
    for(int i = 1; i <= k; i++){
        scanf("%d", &p[i]); mxf = max(mxf, p[i]);
        for(int j = 1; j <= n; j++){
            int x; scanf("%d", &x);
            a[m + (i - 1) * n + j] = {i + n, j, x};
        }
    } //printf("done1\n");
    if(!mxf){
        printf("%lld\n", solve());
        return 0;
    }
    int x = pow(2, k);
    for(int i = 0; i < x; i++){
        int num = i, cnt = 0;
        for(int j = n + 1; j <= n + k; j++) f[j] = num % 2, num /= 2, cnt += (f[j] ? 0 : p[j - n]);
        ans = min(ans, solve() + cnt);
        //printf("done %d %f\n", i, clock() * 1.0 / CLOCKS_PER_SEC);
    } printf("%lld\n", ans);
    return 0;
}
