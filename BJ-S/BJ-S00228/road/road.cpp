#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
#define ll long long
ll n,m,k;
struct edge{
    int u;
    int v;
    int w;
};
edge a[1000010];
ll u,v,w;
ll b[20];
bool Cmp(edge x,edge y){
    return x.w < y.w;
}
int fa[1000010];
int find(int x){
    if(fa[x] == x){
        return x;
    }
    fa[x] = find(fa[x]);
    return fa[x];
}
void uni(int x,int y){
    x = find(x);
    y = find(y);
    fa[x] = y;
}
ll ans;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> k;
    for(int i = 1;i <= n;i ++){
        fa[i] = i;
    }
    for(int i = 1;i <= m;i ++){
        cin >> a[i].u >> a[i].v >> a[i].w;
    }
    for(int i = 1;i <= k;i ++){
        cin >> b[i];
    }
    sort(a + 1,a + 1 + m,Cmp);
    ll cc = 0;
    for(int i = 1;i <= m;i ++){
        if(find(a[i].u) != find(a[i].v)){
            uni(a[i].u,a[i].v);
            ans += a[i].w;
            cc ++;
        }
        if(cc == n - 1){
            break;
        }
    }
    cout << ans << endl; 
    return 0;
}