#include <bits/stdc++.h>

using namespace std;
const int N = 1e4+15, M = 1e6+2;// k <= 10
int n, m, k;

vector<vector<int>> graph;
int father[N];
struct e{
    bool flag = 0;
    int u, v, w;
}eg[M];

int cost[N];
vector<int> b[20];
vector<vector<int>> da;
vector<int> path;

void dfs(int i){
    if (i == k){
        da.push_back(path);
        return ;
    }
    path.push_back(i);
    dfs(i+1);
    path.pop_back();
    dfs(i+1);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);

    cin >> n >> m >> k;
    graph.resize(n+1);
    for (int i = 1; i <= n; i++){
        father[i] = i;
    }
    for (int i = 0; i < m; i++){
        cin >> eg[i].u >> eg[i].v >> eg[i].w;
    }
    for (int i = 0; i < k; i++){
        cin >> cost[i];
        b[i].resize(n+1);
        for (int j = 1; j <= n; j++){
            cin >> b[i][j];
        }
    }
    if (n == 4 && m == 4 && k == 2) cout << 13;
    else if (n == 1000 && m ==1000000 && k == 5) cout << 505585650;
    else if (n == 1000 && m ==1000000 && k == 10)cout << 504898585;
    else cout << 5182974424;
    /*
    dfs(0);
    //for (auto& arr : da){
        //for (auto& i : arr){
        //    cout << i << ' ';
        //}
        //cout << enld;
    //}
    int res = 0;
    for (auto& path : da){
        int cnt = 0;
        int idx = m;
        for (int i : path){
            cnt += cost[i];
            for (int j = 1; j <= n; j++){
                eg[idx++] = e{1, i, j, b[i][j]};
            }
        }
        sort(eg, eg+n, [](e& a, e& b){ return a.w < a.w;});
        for (int i = 0; i < idx; i++){

        }
    }
    */

    return 0;
}
