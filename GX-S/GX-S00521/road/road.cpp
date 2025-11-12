#include <bits/stdc++.h>

using std::cin;
using std::cout;

struct node {
    int next;
    int build_idx;
    long long ws;
    node(int ne, int bi, long long x) {
        next = ne;
        build_idx = bi;
        ws = x;
    }
};
std::vector<std::vector<node>> mp;
bool flag[20005];

long long build[15];
int n,m,k;

bool operator < (node a, node b) {
    long long wa = a.ws;
    if (a.build_idx != -1) wa += build[a.build_idx];
    long long wb = b.ws;
    if (b.build_idx != -1) wb += build[b.build_idx];
    return wa > wb;
}

long long mintree(int start) {
    memset(flag, 0, (n+3)*sizeof(flag[0]));
    long long sum = 0;
    flag[start] = true;

    std::priority_queue<node> pq;
    size_t len = mp[start].size();
    for (size_t i = 0; i < len; ++i) {
        pq.push(mp[start][i]);
    }

    while(!pq.empty()) {
        node top = pq.top();
        pq.pop();

        if (flag[top.next]) continue;
        flag[top.next] = true;
        sum += top.ws;
        if (top.build_idx != -1) {
            sum += build[top.build_idx];
            build[top.build_idx] = 0;
        }
        len = mp[top.next].size();
        for (int i = 0; i < len; ++i) {
            node nex = mp[top.next][i];
            if (flag[nex.next]) continue;
            pq.push(nex);
        }
    }

    return sum;
}

int u,v;
long long w;
long long cs[20005];

int main() {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    scanf("%d%d%d", &n, &m, &k);
    // cin >> n >> m >> k;
    mp.resize(n+3);
    for (int i = 0; i < m; ++i) {
        // in >> u >> v >> w;
        scanf("%d%d%lld", &u, &v, &w);
        mp[u].emplace_back(v, -1, w);
        mp[v].emplace_back(u, -1, w);
    }
    for (int i = 0; i < k; ++i) {
        scanf("%lld", build + i);
        // cin >> build[i];
        for (int j = 0; j < n; ++j) {
            scanf("%lld", cs + j);\
            //cin >> cs[j];
        }
        for (int j = 0; j < n; ++j) {
            for (int j2 = 0; j2 < n; ++j2) {
                if (j2 == j)continue;
                long long x = cs[j+1]+cs[j2+1];
                mp[j+1].emplace_back(j2+1, i, x);
                mp[j2+1].emplace_back(j+1, i, x);
            }
        }
    }
    printf("%lld", mintree(1));
    return 0;
}
