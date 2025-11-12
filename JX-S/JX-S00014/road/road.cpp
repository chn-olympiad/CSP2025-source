#include<bits/stdc++.h>
using namespace std;

int n,m,k,ans;

int r[20],c[20][10010];
struct Node{
    int a,b;
    int money;
}road[1000010];

bool cmp(Node x,Node y){
    return x.money < y.money;
}

int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> k;
    for(int i = 1;i <= m;i++){
        int u,v,w;
        cin >> u >> v >> w;
        road[i].a = u;
        road[i].b = v;
        road[i].money = w;
    }
    for(int i = 1;i <= k;i++){
        cin >> r[i];
        for(int j = 1;j <= n;j++){
            cin >> c[i][j];
        }
    }
    sort(road + 1,road + 1 + m,cmp);
    for(int i = 1;i < m;i++){
        ans += road[i].money;
    }
    cout << ans;

    return 0;
}
