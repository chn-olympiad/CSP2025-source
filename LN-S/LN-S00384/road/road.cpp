# include <algorithm>
# include <iostream>
# include <queue>
# include <vector>

using std::cin;
using std::cout;
using std::vector;

struct dsu {
    struct node {
        int fa;
        int sz;
    };

    vector<node> ds;

    explicit dsu(int n) {
        ds.resize(n);

        for (int i = 0; i < n; ++i) {
            ds[i] = {i, 1};
        }
    }

    int find(int x) {
        return (ds[x].fa == x) ? x : (ds[x].fa = this->find(ds[x].fa));
    }

    void join(int u, int v) {
        if (ds[u].sz < ds[v].sz) {
            std::swap(u, v);
        }

        ds[v].fa = u;
        ds[u].sz += ds[v].sz;
    }
};

struct edge {
    int u, v;
    int w;
    int id, ind;
};

struct cmp_q {
    bool operator ()(const edge &a, const edge &b) const {
        return a.w > b.w;
    }
};

bool cmp(const edge &a, const edge &b) {
    return a.w < b.w;
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    std::freopen("road.in", "r", stdin);
    std::freopen("road.out", "w", stdout);

    int n, m, k;
    cin >> n >> m >> k;

    vector<edge> edges(m);

    for (auto &e: edges) {
        cin >> e.u >> e.v >> e.w;
        e.u -= 1;
        e.v -= 1;
        e.id = -1;
    }

    std::sort(edges.begin(), edges.end(), cmp);

    dsu ds(n);

    vector<edge> useful;
    useful.reserve(n - 1);
    
    for (const auto &e: edges) {
        int u = ds.find(e.u), v = ds.find(e.v);

        if (u == v) {
            continue;
        }

        useful.push_back(e);
        ds.join(u, v);
    }

    vector<int> cost(k);
    vector<vector<edge>> news(k, vector<edge>(n));

    for (int i = 0; i < k; ++i) {
        cin >> cost[i];

        for (int u = 0; u < n; ++u) {
            int a;
            cin >> a;

            news[i][u] = {n + i, u, a, i};
        }

        std::sort(news[i].begin(), news[i].end(), cmp);
    }

    long long final_ans = 0x3f3f3f3f3f3f3f3f;

    for (int s = 0; s < (1 << k); ++s) {
        long long cur_ans = 0;
        int tot = n;

        std::priority_queue<edge, vector<edge>, cmp_q> options;

        useful[0].ind = 0;
        options.push(useful[0]);
        for (int i = 0; i < k; ++i) {
            if (!((s >> i) & 1)) {
                continue;
            }

            tot += 1;
            cur_ans += cost[i];

            news[i][0].ind = 0;
            options.push(news[i][0]);
        }

        int e_cnt = 1;
        dsu ds(n + k);

        while (e_cnt < tot) {
            edge cur = options.top();
            options.pop();

            if (cur.id < 0) {
                if (cur.ind < n - 2) {
                    useful[cur.ind + 1].ind = cur.ind + 1;
                    options.push(useful[cur.ind + 1]);
                }
            } else {
                if (cur.ind < n - 1) {
                    news[cur.id][cur.ind + 1].ind = cur.ind + 1;
                    options.push(news[cur.id][cur.ind + 1]);
                }
            }

            int u = ds.find(cur.u), v = ds.find(cur.v);

            if (u == v) {
                continue;
            }

            cur_ans += cur.w;
            ds.join(u, v);
            e_cnt += 1;
        }

        final_ans = std::min(final_ans, cur_ans);
    }

    cout << final_ans;

    return 0;
}
