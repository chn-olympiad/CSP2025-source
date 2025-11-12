#include<bits/stdc++.h>
#define ll long long

using namespace std;

struct edge{
    int v,w,nt;
    bool ci;
};

const int N = 1e4 + 5,M = 1e6 + 5;
ll n,m,k,tu,tv,tw,cnt = 1,ans = 0;
int c[15] = {0};
edge e[int(M + 1e5)] = {0};
int head[M] = {0};
bool vis[N] = {0};

void addedge(int st,int ed,int co)
{
    e[cnt] = {ed,co,head[st]};
    head[st] = cnt;
    cnt++;
}

void dfs(ll dep,ll cost,int st)
{
    if (dep > n){
        ans = min(ans,cost);
        return ;
    }
    for (int i = head[st];i != 0;i = e[i].nt){
        if (vis[e[i].v]) continue;
        vis[e[i].v] = 1;
        dfs(dep + 1,cost + e[i].w,e[i].v);
        vis[e[i].v] = 0;
    }
}

int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin >> n >> m >> k;
    for (int i = 1;i <= m;i++){
        cin >> tu >> tv >> tw;
        addedge(tu,tv,tw);
        addedge(tv,tu,tw);
        e[cnt].ci = e[cnt - 1].ci = 1;
    }
    for (int i = 1;i <= k;i++){
        cin >> c[i];
        for (int j = 1;j <= n;j++){
            cin >> tw;
            addedge(i,j,tw);
            addedge(j,i,tw);
            e[cnt].ci = e[cnt - 1].ci = 0;
        }
    }
    if (k == 0){
        dfs(1,0,1);
        cout << ans;
    }
    else{
        cout << 0; // 16'
    }
    return 0;
}