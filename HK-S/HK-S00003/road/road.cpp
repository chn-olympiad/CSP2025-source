#include <bits/stdc++.h>
using namespace std;
const int N = 10100;
struct e{
    int d;
    long long c; //d = destination, c = cost
};
vector<vector<e> > neigh(N);
ifstream input("road.in");
ofstream output("road.out");
int n, m, k, t;
int u, v;
long long w, ans, rem;
bool visited[N];
priority_queue<pair<long long, int>, vector<pair<long long, int> >, greater<pair<long long, int> > > pq;//{cost, node id}
inline void mst(){
    pq.push({0, 1});
    while (!pq.empty() && rem){
        auto tmp = pq.top();
        //cout << tmp.second << endl;
        pq.pop();
        if (visited[tmp.second]){
            continue;
        }
        ans += tmp.first;
        --rem;
        visited[tmp.second] = 1;
        for (e i : neigh[tmp.second]){
            if (!visited[i.d]){
                pq.push({i.c, i.d});
            }
        }
    }
}
void sub1(){
    int c;
    t = n + k;
    rem = t;
    for (int i = 1; i <= m; i++){
        input >> u >> v >> w;
        neigh[u].push_back({v, w});
        neigh[v].push_back({u, w});
    }
    //cout << w << endl;
    for (int i = 1; i <= k; i++){
        input >> c;
        for (int j = 1; j <= n; j++){
            input >> w;
            neigh[n + i].push_back({j, w});
            neigh[j].push_back({n + i, w});
        }
    }
    mst();
    output << ans << '\n';
}
int main(){

    ios::sync_with_stdio(false);
    input.tie(0);
    input >> n >> m >> k;
    sub1();
    input.close();
    output.close();
    //fclose(stdin);
    //fclose(stdout);
    return 0;
}



