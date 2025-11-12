

#include <bits/stdc++.h>

using namespace std;

struct Road{
    long long to,cost;
};
struct Node{
    long long pos,weight;

    bool operator < (const Node &x) const {
        return x.weight < weight;
    }
};

vector<Road> _myList[1019];
long long n,m,k;
long long ans = 0;
priority_queue<Node> pq;
long long dis[1009];
bool vis[1009];

void Prim(int s) {
    Node solo;
    solo.pos = 1;
    solo.weight = 0;
    pq.push(solo);

    while(!pq.empty()) {

        solo = pq.top();
        pq.pop();

        if(vis[solo.pos]) {
            continue;
        }
        vis[solo.pos] = true;

        for(int i = 0; i < _myList[solo.pos].size(); i++) {
            Road cur = _myList[solo.pos][i];

            if(cur.cost < dis[cur.to] && !vis[cur.to]) {
                dis[cur.to] = cur.cost;
                pq.push({cur.to,cur.cost});
            }
        }
    }
}

int main () {
    freopen("road.in","r", stdin);
    freopen("road.out","w", stdout);

    cin >> n >> m >> k;

    for(int i = 1; i <= m; i++) {
        long long u,v,w;
        Road solo;
        cin >> u >> v >> w;
        solo.cost = w;
        solo.to = v;
        _myList[u].push_back(solo);
        solo.to = u;
        _myList[v].push_back(solo);
    }

    for(int i = 2; i <= n; i++) {
        dis[i] = 100000000009;
    }

    if(k == 0) {
        Prim(1);
        for(int i = 1; i <= n; i++) {
            ans += dis[i];
        }
        cout << ans << endl;
        return 0;
    }

    for(int i = 1; i <= k; i++) {
        long long c,d;
        Road solo;
        cin >> c;
        dis[i + n] = c;
        for(int j = 1; j <= n; j++) {
            cin >> d;
            solo.to = j;
            solo.cost = d;
            _myList[i + n].push_back(solo);
            solo.to = i + n;
            _myList[j].push_back(solo);
        }
    }

    for(int i = 1; i <= n + k; i++) {
        ans += dis[i];
//        cout << dis[i] << endl;
    }

    cout << ans << endl;

    return 0;
}
