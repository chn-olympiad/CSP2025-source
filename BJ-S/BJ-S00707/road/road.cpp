#include <bits/stdc++.h>
using namespace std;
struct st{
    int x;
    int y;
    int z;
}b[1000005];
int n,m,k,a[12][10005],c[15],ans,mp[10005][10005];
bool vis[10005],flag;
vector<int> v[10005];
void check(int e,int f,int x,int fa,int now){
    vis[x] = 1;
    if(now == n){
        for(int i = 1;i <= n;i++) if(vis[i] == 0) return;
        flag = 1;
        return;
    }
    for(int i = 0;i < v[x].size();i++){
        int u = v[x][i];
        if(mp[x][u] == 0) continue;
        if(u == fa) continue;
        if(x == e && u == f) continue;
        if(vis[u] == 0){
            check(e,f,u,x,now + 1);
        }
    }
}
void dfs(int x){
    for(int i = x;i <= m;i++){
        flag = 0;
        memset(vis,0,sizeof(vis));
        check(b[i].x,b[i].y,1,0,1);
        printf("%d %d\n",b[i].x,b[i].y);
        if(flag == 1){
            ans -= mp[b[i].x][b[i].y];
            mp[b[i].x][b[i].y] = 0;
            mp[b[i].y][b[i].x] = 0;
            dfs(i + 1);
        }
    }
}
bool cmp(st s,st g){
    return s.z > g.z;
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%d%d%d",&n,&m,&k);
    for(int i = 1;i <= m;i++){
        scanf("%d%d%d",&b[i].x,&b[i].y,&b[i].z);
        v[b[i].x].push_back(b[i].y);
        v[b[i].y].push_back(b[i].x);
        mp[b[i].x][b[i].y] = b[i].z;
        mp[b[i].y][b[i].x] = b[i].z;
        ans += b[i].z;
    }
    for(int i = 1;i <= k;i++){
        scanf("%d",&c[i]);
        for(int j = 1;j <= n;j++) scanf("%d",&a[i][j]);
    }
    if(k == 0){
        sort(b + 1,b + n + 1,cmp);
        dfs(1);
        printf("%d",ans);
    }
    return 0;
}
