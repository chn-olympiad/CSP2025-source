#include <bits/stdc++.h>
using namespace std;

const int N=1e4,M=1e6,K=10;
int n,m,k,c[K+5][N+5],ans;

struct Node{
    int to,need;
};

vector <Node> g[M+5];

void fun(int x, int last){
    if(g[x].size()!=1){
        int nmin=0x3f3f3f3f,next;
        for(int i=0; i<g[x].size(); i++){
            if(g[x][i].need<=nmin && g[x][i].to!=last){
                nmin=g[x][i].need;
                next=g[x][i].to;
            }
        }
        ans+=nmin;
        fun(next, x);
    }else if(g[x][0].to!=last){
        ans+=g[x][0].need;
        fun(g[x][0].to, x);
    }
    return;
}

int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m >> k;
    while(m--){
        int u,v,w;
        cin >> u >> v >> w;
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }
    for(int i=1; i<=k; i++){
        cin >> c[i][0];
        for(int j=1; j<=n; j++){
            cin >> c[i][j];
        }
    }
    //if k==0 || (k!=0 && c[j]==0 && a[i][j]==0)
    fun(1, 0);
    cout << ans;
    return 0;
}
