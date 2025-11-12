#include <bits/stdc++.h>
using namespace std;
int n , m , k;
int mw[11];
struct node{
    int u , v , w;
};
vector<node> ve[1000011];
queue<node> q;
//void bfs(){
//    q.push(ve[0]);
//}
long long ans;
int main(){
    freopen("road.in" , "r" , stdin);
    freopen("road.out" , "w" , stdout);
    cin >> n >> m >> k;
    for (int i = 0 ; i < m ; i ++){
        int u , v , w;
        cin >> u >> v >> w;
        ve[u].push_back({u , v , w});
        ve[v].push_back({v , u , w});
        ans += w;
    }
    for (int i = 0 ; i < k ; i ++){
        cin >> mw[i];
        for (int j = 1 ; j <= n ; j ++){
            int tmp;
            cin >> tmp;
            ve[m + i].push_back({m + i , j , tmp});
            ve[j].push_back({j , m + i , tmp});
        }
    }
    //bfs();
    cout << ans;
    return 0;
}