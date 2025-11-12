#include <bits/stdc++.h>
using namespace std;
#define int long long
#define MAXN 20005
#define MAXK 15
#define MAXM 2000005
int n,m,k;
struct BIAN{
    int u,v; long long w; bool ok;
    bool operator <(const BIAN ano){
        if(ok == 1 && ano.ok == 0) return 1;
        else if(ok == 0 && ano.ok == 1) return 0;
        else return w < ano.w;
    }
}e1[MAXM],e[MAXN << 4],e2[MAXN << 4];
int p[MAXN];
int c[MAXK];
int findfa(int x){
    if(x == p[x]) return x;
    else return p[x] = findfa(p[x]);
}
signed main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%lld%lld%lld",&n,&m,&k);
    for(int i = 1; i <= m; i++){
        int u,v,w; scanf("%lld%lld%lld",&u,&v,&w);
        e1[i].u = u,e1[i].v = v,e1[i].w = w,e1[i].ok = 1;
    }
    long long leas = 0;
    sort(e1 + 1,e1 + m + 1);
    for(int i = 1; i <= n; i++) p[i] = i;
    for(int i = 1; i <= m; i++){
        int x = findfa(e1[i].u),y = findfa(e1[i].v);
        if(x == y) {
            e1[i].ok = 0; continue;
        }
        p[x] = y; leas += e1[i].w;
    }
    int nowcount = 0;
    for(int i = 1; i <= m; i++){
        if(e1[i].ok) nowcount++,e2[nowcount] = e1[i],e[nowcount] = e1[i];
    }
    for(int i = 1; i <= k; i++){
        scanf("%lld",&c[i]);
        for(int j = 1; j < n; j++) e2[j] = e[j];
        for(int j = n; j < 2*n; j++){
            long long tmp; scanf("%lld",&tmp);
            e2[j].u = j-n+1;
            e2[j].v = n+1;
            e2[j].w = tmp;
            e2[j].ok = 1;
        }
        sort(e2 + 1,e2 + 2*n);
        for(int j = 1; j <= n+1; j++) p[j] = j;
        for(int j = 1; j < 2*n; j++){
            int x = findfa(e2[j].u),y = findfa(e2[j].v);
            if(x == y) {
                e2[j].ok = 0; continue;
            }
            p[x] = y; 
        }
        for(int j = 1; j < 2*n; j++){
            if(e2[j].v != n+1) continue;
            else{
                if(e2[j].ok == 1){
                    nowcount++;
                    e[nowcount].u = e2[j].u,e[nowcount].v = i+n,e[nowcount].w = e2[j].w,e[nowcount].ok = 1;
                }
            }
        }
    }
    sort(e+1,e+nowcount+1);
    int ans = leas;
    for(int i = 0; i < (1 << k); i++){
        int a[15]; 
        int sum = 0;
        for(int j = 0; j < k; j++){
            if(i & (1 << j)) a[j] = 1,sum = sum + c[j+1]; 
            else a[j] = 0;
        }
        for(int j = 1; j <= nowcount; j++){
            if(e[j].v <= n) continue;
            if(a[e[j].v - n - 1] == 0) e[j].ok = 0;
            else e[j].ok = 1;
        }

        for(int j = 1; j <= n+k; j++) p[j] = j;
        for(int j = 1; j <= nowcount; j++){
            if(e[j].ok == 0) continue;
            int x = findfa(e[j].u),y = findfa(e[j].v);
            if(x == y) {
                continue;
            }
            p[x] = y; sum = sum + e[j].w;
            if(sum >= ans) break;
        }
        ans = min(ans,sum);
    }
    printf("%lld\n",ans);
    return 0;
}