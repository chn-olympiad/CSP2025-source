#include<iostream>
#include<queue>
#include<bits/stdc++.h>
#include<vector>
#define INF 0xffffffff
#define ll long long
#define NMAX 15000
#define MMAX 7005000
using namespace std;
ll head[NMAX] = {0}, ecnt = 0;
ll cu[15];
ll n,m,k;
ll ans = 0;
int f[NMAX];
bool fg[NMAX] = {false};
struct EDGE{
    int u,v;
    ll nxt;
    ll w;
}e[MMAX];
int find(int x){
    if(x == f[x])return x;
    else return (f[x] = find(f[x]));
}
void add(int u,int v,ll w){
    ecnt++;
    e[ecnt].v = v;
    e[ecnt].u = u;
    e[ecnt].w = w;
    e[ecnt].nxt = head[u];
    head[u] = ecnt;
}
bool bmp(EDGE a,EDGE b){
    return (a.w < b.w);
}
void kruskal(){
    sort(e + 1,e + ecnt + 1,bmp);
    int u,v;
    for(int i = 1;i <= ecnt;i++){
        u = e[i].u;
        v = e[i].v;
       // cout << i << " u:" << u << " v:" << v << " w:" << e[i].w;
        if(find(u) != find(v)){
            //cout << "   Merge!" << endl;
            ans += e[i].w;
            int fu = find(u),fv = find(v);
            f[fu] = fv;

        }//else cout << endl;
    }
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    //cin.tie(0);
    cin >> n >> m >> k;
    for(int i = 1;i <= n + k;i++)f[i] = i;
    //for(int i = 1;i <= n + k;i++)cout << f[i] << ' ';
    //cout << endl;
    ll tx,ty,tw;   //for input
    for(int i = 0; i < m;i++){
        cin >> tx >> ty >> tw;
        add(tx,ty,tw);
        add(ty,tx,tw);
    }

    for(int i = 1;i <= k;i++){
        cin >> cu[i];
        for(int  j = 1;j <= n;j++){
            cin >> tx;
            add(n + i,j,cu[i] + tx);
            add(j,n + i,cu[i] + tx);
        }
    }
    kruskal();
    cout << ans << endl;
    return 0;
}
