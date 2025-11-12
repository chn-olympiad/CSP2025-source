#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
int n,m,k,cnt,ans = 1e18;
int b[15][10005],p[10015],c[15];
bool vis[15];
struct node{
    int x,y,w;
}a[1000005],e[2000005];
int find(int x){
    return p[x]==x ? x : p[x] = find(p[x]);
}
bool cmp(node x,node y){
    return x.w<y.w;
}
void dfs(int x){
    if(x==k+1){
        for(int i=1;i<=n+k;i++){
            p[i] = i;
        }
        cnt = 0;
        for(int i=1;i<=m;i++){
            int x = 1e18;
            for(int j=1;j<=k;j++){
                if(vis[j]){
                    x = min(x,b[j][a[i].x]+b[j][a[i].y]);
                }
            }
            if(a[i].w<x){
                e[++cnt] = a[i];
            }
        }
        int sum = 0;
        for(int i=1;i<=k;i++){
            if(!vis[i]){
                continue;
            }
            sum+=c[i];
            if(sum>=ans){
                return;
            }
            for(int j=1;j<=n;j++){
                e[++cnt] = {n+i,j,b[i][j]};
            }
        }
//        cout << cnt << endl;
        sort(e+1,e+cnt+1,cmp);
        for(int i=1;i<=cnt;i++){
            int x = find(e[i].x),y = find(e[i].y);
//            cout << x << " " << y << " " << i << endl;
            if(x!=y){
                p[x] = y;
                sum+=e[i].w;
                if(sum>=ans){
                    return;
                }
            }
        }
//        cout << sum << endl;
        ans = sum;
        return;
    }
    dfs(x+1);
    vis[x] = 1;
    dfs(x+1);
    vis[x] = 0;
}
signed main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> k;
    for(int i=1;i<=m;i++){
        cin >> a[i].x >> a[i].y >> a[i].w;
    }
    bool flag = 0;
    for(int i=1;i<=k;i++){
        cin >> c[i];
        if(c[i]){
            flag = 1;
        }
        for(int j=1;j<=n;j++){
            cin >> b[i][j];
        }
    }
    if(!flag){
        for(int i=1;i<=n+k;i++){
            p[i] = i;
        }
        for(int i=1;i<=m;i++){
            e[i] = a[i];
        }
        cnt = m;
        int sum = 0;
        for(int i=1;i<=k;i++){
            for(int j=1;j<=n;j++){
                e[++cnt] = {n+i,j,b[i][j]};
            }
        }
        sort(e+1,e+cnt+1,cmp);
        for(int i=1;i<=cnt;i++){
            int x = find(e[i].x),y = find(e[i].y);
            if(x!=y){
                p[x] = y;
                sum+=e[i].w;
            }
        }
        cout << sum;
        return 0;
    }
    dfs(1);
    cout << ans;
    return 0;
}
