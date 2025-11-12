#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,m2,k,fa[10050],c[15],now[15],sz[10050],aaa;
ll ans1,ans;
pair<int,pair<int,int> > e[1000005],e2[100005];
pair<int,int> a[15][10005];
inline int find(int x){
    if(fa[x] == x) return x;
    return fa[x] = find(fa[x]);
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin >> n >> m >> k;
    for(int i = 1;i <= m;i++){
        int u,v,w;
        cin >> u >> v >> w;
        e[i] = {w,{u,v}};
    }
    sort(e + 1,e + m + 1);
    for(int i = 1;i <= n;i++) fa[i] = i;
    for(int i = 1;i <= m;i++){
        int tx = find(e[i].second.first),ty = find(e[i].second.second);
        if(tx != ty){
            e2[++m2] = e[i];
            fa[ty] = tx;
        }
    }
    for(int i = 1;i <= k;i++){
        cin >> c[i];
        for(int j = 1;j <= n;j++) cin >> a[i][j].first,a[i][j].second = j;
        sort(a[i] + 1,a[i] + n + 1);
    }
    ans = 0x3f3f3f3f3f3f3f3f;
    for(int i = 0;i < (1 << k);i++){
        ans1 = now[0] = 0;
        int cnt = 0;
        for(int j = 1;j <= k;j++){
            if((i >> (j - 1)) & 1){
                ans1 += c[j];
                now[j] = 0;
                cnt++;
            }else now[j] = n;
        }
        for(int j = 1;j <= n + k;j++) fa[j] = j,sz[j] = 1;
        int msz = 1;
        for(int j = 1;;j++){
            int t = 0,tmp = 0;
            for(int l = 1;l <= k;l++){
                if(now[l] < n && (!t || a[l][now[l] + 1].first < a[t][now[t] + 1].first)) t = l;
            }
            if(now[0] < n - 1 && (!t || e2[now[0] + 1].first < a[t][now[t] + 1].first)) t = 0;
            now[t]++;
            int tx,ty;
            if(!t){
                tx = find(e2[now[0]].second.first),ty = find(e2[now[0]].second.second);
                tmp = e2[now[0]].first;
            }else{
                tx = find(t + n),ty = find(a[t][now[t]].second);
                tmp = a[t][now[t]].first;
                //cout << t << '*' << a[t][now[t]].first << ' ';
            }
            if(tx != ty){
                //cout << t <<'-' << tx << ' ' << ty <<' ';
                fa[ty] = tx;
                sz[tx] += sz[ty];
                ans1 += tmp;
                msz = max(msz,sz[tx]);
                //cout << ans1 << '\n';
            }
            if(msz == n + cnt || ans1 >= ans) break;
        }
        ans = min(ans,ans1);
        //cout << ans1 << '\n';
    }
    cout << ans;
    return 0;
}
