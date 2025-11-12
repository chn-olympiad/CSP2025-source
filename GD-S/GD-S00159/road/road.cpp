#include <bits/stdc++.h>
using namespace std;

int n, m, k;
vector< vector< pair<int, int> > > cities; // cities[start] = [(dest, cost), ...]

struct Sorter{
    bool operator()(const pair< int, pair<int, int> >& a, const pair< int, pair<int,int> >& b){
        return a.second.second > b.second.second;
    }
};

vector<int> dijkstra(int start){
    priority_queue< pair<int, pair<int, int> >, vector< pair<int, pair<int, int> > >, Sorter> pending;
    vector<int> result(n+k+1);
    
    fill(result.begin(), result.end(), INT_MAX);
    result[start] = 0;
    for(auto& i : cities[start]){
        pending.push(make_pair(start, i));
    }

    while(!pending.empty()){
        auto path = pending.top();
        int curr = path.second.first, last = path.first, val = path.second.second;
        int newResult = min(result[curr], result[last]+val);
        // cout << "going from " << last << ", which costs " << result[last] << ", to " << curr << ", costs " << val << endl;
        pending.pop();
        if(result[curr]!=newResult)
            for(auto& i : cities[curr]) 
                if(i.first!=last)
                    pending.push(make_pair(curr, i));
        result[curr] = newResult;
    }

    return result;
}

int main(){
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> k;

    cities.resize(n+k+1);

    for(int i=0;i<m;i++){
        int u, v, w;
        cin >> u >> v >> w;
        cities[u].push_back(make_pair(v, w));
        cities[v].push_back(make_pair(u, w));
    }

    for(int i=n+1;i<=n+k;i++){
        int c;
        cin >> c;
        for(int j=1;j<=n;j++){
            int v;
            cin >> v;
            cities[j].push_back(make_pair(i, v+c));
            cities[i].push_back(make_pair(j, v));
        }
    }
    
    // for(int i=0;i<=n+k;i++){
    	// cout << i << ": ";
    	// for(auto j : cities[i]) cout << "(" << j.first << ", " << j.second << "), ";
    	// cout << endl;
    // }

    for(int i=1;i<=1;i++){
        auto m = dijkstra(i);
        // for(int j : m) cout << j << " ";
        cout << m[n];//endl;
    }
    
    

    return 0;
}