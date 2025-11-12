#include <bits/stdc++.h>
using namespace std;

const int M = 1e6+5, N = 1e4+5;

struct road {
    pair<int , int>p;
    int w, km;
};
road a[M];

bool cmp(road x, road y){
    return x.w < y.w;
}

struct node {
    pair<int, int> p;
    queue<vector<int>, pair<int, int> >s;
    int w;
    void get_s(int w, int u, int v){
        s.push(w, {u, v});
    }
    void __init__ () {
        if(!s.empty()) {
            auto z = s.front();
            for(auto e : s.front()) {}
        }
    }
};

int main() {
    int n, m, k, c[N];
    long long all = 0;
    cin >> n >> m >> k;
    for(int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y >> a[i].w;
        a[i].p = {x, y};
        a[i].km = 0;
        all += a[i].w;
    }
    for(int i = 1; i <= k; i++) {
        cin >> c[i];
        for(int j = 1; j <= n; j++) {
            int temp; cin >> temp;
            a[m+j].w = temp;
            a[m+j].km = j;
            a[i+j].p = {n+i, j};
        }
    }
    sort(a, a+m+k, cmp);
    int cnt = 0;
    bool vis[N];
    memset(vis, false, sizeof(vis));
    for(int i = 1; i <= m+k; i++) {
        vis[1] = true;

    }
    cout << all << endl;
    return 0;
}
