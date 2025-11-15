#include <bits/stdc++.h>

using namespace std;

int p[10000 + 100];

int dsu(int k){
    if(p[k] == k) return k;
    return p[k] = dsu(p[k]);
}

int main(){
    ifstream cin("road.in");
    ofstream cout("road.out");
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> edge;
    for(int i = 0; i < m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        edge.push_back({w, u, v});
    }
    sort(edge.begin(), edge.end());
    int c[k + 1];
    int a[k + 1][n + 1];
    for(int i = 1; i <= k; i++){
        cin >> c[i];
        for(int j = 1; j <= n; j++){
            cin >> a[i][j];
        }
    }
    long long ans = LONG_LONG_MAX;
    for(int b = 0; b < (1 << k); b++){
        long long res = 0;
        vector<vector<int>> v;
        for(int i = 0; i < k; i++){
            if(b & (1 << i)){
                res += c[i + 1];
                for(int j = 1; j <= n; j++) v.push_back({a[i + 1][j], i + 1 + n, j});
            }
        }
        int pt1 = 0;
        int pt2 = 0;
        sort(v.begin(), v.end());
        for(int i = 1; i <= n + k; i++){
            p[i] = i;
        }
        int cnt = 0;
        while(pt1 < edge.size() || pt2 < v.size()){
            int w, fst, snd;
            w = INT_MAX;
            bool nga;
            if(pt1 < edge.size()){
                w = edge[pt1][0];
                fst = edge[pt1][1];
                snd = edge[pt1][2];
                nga = 0;
            }
            if(pt2 < v.size() && v[pt2][0] <= w){
                w = v[pt2][0];
                fst = v[pt2][1];
                snd = v[pt2][2];
                nga = 1;
            }
            if(nga) pt2++;
            else pt1++;
            if(dsu(fst) != dsu(snd)){
                cnt++;
                res += w;
                p[dsu(fst)] = dsu(snd);
            }
            if(cnt >= n + k) break;
        }
        ans = min(ans, res);
    }
    cout << ans << '\n';
    return 0;
}