#include<bits/stdc++.h>
using namespace std;
const int N = 1e4 + 5;
const int M = 1e6 + 5;
int n,m,k;
struct node{
    int x,y,w;
}p[M];
bool vis[N];
bool cmp(node a,node b){
    return a.w < b.w;
}
int bcj[N];
int q(int x){
    if(bcj[x] = x)return x;
    else return bcj[x] = q(bcj[x]);
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin >> n >> m >> k;
    for(int i = 1; i <= n; ++i){
        bcj[i] = i;
    }
    for(int i = 1; i <= m; ++i){
        int u,v,W;
        cin >> u >> v >> W;
        p[i].w = W;
        p[i].x = min(u,v);
        p[i].y = max(u,v);
    }

    sort(p + 1,p + m + 1,cmp);
    long long ans = 0;
    for(int i = 1; i <= m; ++i){
        int x = p[i].x, y = p[i].y;
        if(bcj[x] == bcj[y])continue;
        bcj[x] = q(y);
        ans += p[i].w;
    }
    for(int i = 1; i <= n; ++i){
        cout << bcj[i] << '\n';
    }
    cout << ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
/*
7 10 0
1
*/
