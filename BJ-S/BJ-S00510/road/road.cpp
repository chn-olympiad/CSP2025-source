#include <iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<vector>
using namespace std;
long long n, m, k, a[15], b[15][12005], cnt, ans = 9e18, h[12005], he[12005];
struct node{
    long long u, v, w;
}s[2000005];
bool cmp(node x, node y){
    return x.w < y.w;
}
long long fin(long long k){
    if(he[k] == k) return k;
    he[k] = fin(he[k]);
    return he[k];
}
void merg(long long x, long long y){
    he[fin(x)] = fin(y);
}
long long cou(long long op){
    //cout << op << endl;
    long long l = 0, i = 0, ab =0;
    for(int i = 1;i <= n + k;i++) he[i] = i;
    while(l < op-1){
        //cout << i << endl;
        i++;
        if(fin(s[i].u) != fin(s[i].v) && ((s[i].u <= n || h[s[i].u - n] == 1) && (s[i].v <= n || h[s[i].v - n] == 1))){
            ab += s[i].w;
            l++;
            merg(s[i].u, s[i].v);
        }
        //cout << s[i].v << " " << s[i].u << " " << l << endl;
    }
    return ab;
}
void dfs(int step, long long cnt1, long long op){
    if(cnt1 >= ans) return;
    if(step == k+1){
        //cout << h[1] << " " << h[2] << endl;
        long long o = cou(op);
        ans = min(ans, o + cnt1);
        return;
    }
    dfs(step+1, cnt1, op);
    cnt1 += a[step];
    h[step] = 1;
    dfs(step+1, cnt1, op+1);
    h[step] = 0;
}
int main()
{
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    scanf("%lld %lld %lld", &n, &m, &k);
    for(int i = 1;i <= m;i++){
        scanf("%lld %lld %lld", &s[i].u, &s[i].v, &s[i].w);
    }
    cnt = m;
    for(int i = 1;i <= k;i++){
        scanf("%lld", &a[i]);
        for(int j = 1;j <= n;j++){
            scanf("%lld", &b[i][j]);
            s[++cnt].u = n + i;
            s[cnt].v = j;
            s[cnt].w = b[i][j];
        }
    }
    //cout << 1 << endl;
    sort(s+1, s+cnt+1, cmp);
    //cout << 1 << endl;
    dfs(1, 0, n);
    //cout << 1 << endl;
    cout << ans;
    return 0;
}
