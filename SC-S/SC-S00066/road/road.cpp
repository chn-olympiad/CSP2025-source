#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e4 + 10,M = 1e6 + 10;
int n,m,k,ans = LLONG_MAX,fa[N],a[15][N];
bool vis[15];
vector<int> v;
struct node{
    int u,v,w;
}e[M];
struct que{
    int u,v,d;
    bool operator < (const que& u) const{return u.d < d;}
};
int find(int x){
    if(x != fa[x]) fa[x] = find(fa[x]);
    return fa[x];
}
void  update(int x,int y){
    x = find(x);
    y = find(y);
    fa[x] = y;
}
int mintree(){
    priority_queue<que> q;
    int cnt = 0;
    for(int i = 1;i <= m;i++) q.push({e[i].u,e[i].v,e[i].w});
    for(int i = 0;i < v.size();i++){
        for(int j = 1;j <= n;j++)
            q.push({v[i],j,a[v[i]-n][j]});
        cnt += a[v[i]-n][0];
    }
    for(int i = 0;i <= n + k;i++) fa[i] = i;
    while(!q.empty()){
        auto x = q.top();q.pop();
        if(find(x.u) != find(x.v)){
            update(x.u,x.v);
            cnt += x.d;
        }
    }
    //cout << cnt << endl;
    return cnt;
}
void dfs(int h,int j){
    //for(int i = 0;i < v.size();i++) cout << v[i] << " ";
    ans = min(ans,mintree());
    if(h == k) return;
    for(int i = j + 1;i <= k;i++){
        if(!vis[i]){
            vis[i] = 1;
            v.push_back(i+n);
            dfs(h + 1,i);
            vis[i] = 0;
            v.pop_back();
        }
    }
}
signed main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%lld%lld%lld",&n,&m,&k);
    for(int i = 1;i <= m;i++) scanf("%lld%lld%lld",&e[i].u,&e[i].v,&e[i].w);
    bool flag = 0;
    for(int i = 1;i <= k;i++)
        for(int j = 0;j <= n;j++){
            scanf("%lld",&a[i][j]);
            if(a[i][j]) flag = 1;
        }
    if(flag) dfs(0,0);
    else{cout << 0;return 0;}
    cout << ans;
    return 0;
}
