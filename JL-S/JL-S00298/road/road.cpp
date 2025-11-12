#include<bits/stdc++.h>
using namespace std;
const int N=101010;
vector<pair<int, int> > road[N];
vector<pair<int, int> > vec[N];
int main(){
//    freopen("road.in", "r", stdin);
//    freopen("road.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, m, k;
    cin>>n>>m>>k;
    for(int i=1; i<=m; i++){
        int a, b, c;
        cin>>a>>b>>c;
        road[a].push_back({b, c});
        road[b].push_back({a, c});
    }
    for(int i=1; i<=k; i++){
        int a;
        cin>>a;
        for(int i=1; i<=n; i++){
            int x;
            cin>>x;
            vec[a].push_back({x+a, i});
        }
    }
    return 0;
}
