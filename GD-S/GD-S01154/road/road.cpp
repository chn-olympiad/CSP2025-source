#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;

struct Edg {
    int nb;
    int val;
    bool operator< (const Edg& other) const {
        return other.val < val;
    }
};

int N,M,K;
vector<Edg> G[MAXN];
int vill[15];
bool vis[MAXN] = {0};

int main() {
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin >> N >> M >> K;
    for(int i=1; i<=M; i++) {
        int u,v,w;
        cin >> u >> v >> w;
        G[u].push_back(Edg{v,w});
        G[v].push_back(Edg{u,w});
    }
    bool flag = true;
    for(int i=1; i<=K; i++) {
        cin >> vill[i];
        if (vill[i] != 0) flag = false;
        for(int j=1; j<=N; j++) {
            int num;
            cin >> num;
            if (num != 0) flag = false;
            G[N + i].push_back(Edg{j,num});
            G[j].push_back(Edg{N + i,num});
        }
    }
    if (flag) {
        cout << 0;
        return 0;
    }

    priority_queue<Edg> pq;
    pq.push(Edg{1,0});
    int cnt = 0;
    long long ans = 0;
    while (!pq.empty()) {
        // cout << "?";
        Edg cur = pq.top();
        pq.pop();
        if (vis[cur.nb]) continue;
        if (cur.nb <= N) {
            cnt++;
        }
        ans += cur.val;
        vis[cur.nb] = 1;
        if (cnt == N - 1) break;
        // cout << "?";
        for(int i=0; i<G[cur.nb].size(); i++) {
            int nb = G[cur.nb][i].nb;
            if (vis[nb]) continue;
            pq.push(Edg{G[cur.nb][i].nb,G[cur.nb][i].val + vill[nb - N]});
        }
    }
    cout << ans;

    return 0;
}