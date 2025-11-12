#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
int n,m,k,ans = 0x3f;
int a[15][1005],b[15];
bool vis[15];
vector<int>q[N];
vector<int>p[N];
bool flag = 0;
void dfs(int x,int res){
    if (x == 1 && flag == 1){
        ans = min(ans,res);
        return;
    }
    flag = 1;
    int i = 0;
    while (q[x][i] != 0){
        if (vis[q[x][i]] == 0){
            vis[q[x][i]] = 1;
            dfs(q[x][i],res + p[x][i]);
            vis[q[x][i]] = 0;
        }
        i++;
    }
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%d%d%d",&n,&m,&k);
    for (int i = 1;i <= m;i++){
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        q[u].push_back(v);
        q[v].push_back(u);
        p[u].push_back(w);
        p[v].push_back(w);
    }
    for (int j = 1;j <= k;j++){
        scanf("%d",&b[j]);
        for (int i = 1;i <= n;i++){
            int w;
            scanf("%d",&w);
            a[j][i] = w;
        }
    }
    dfs(1,0);
    printf("%d",ans);
    return 0;
}