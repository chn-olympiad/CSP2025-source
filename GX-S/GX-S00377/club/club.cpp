#include <bits/stdc++.h>
using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b) { return a.first > b.first; }

int main() {
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);

    int t; scanf("%d", &t);
    while(t--) {
        int ans = 0;
        int n; scanf("%d", &n);
        vector<vector<pair<int, int> > > a(n, vector<pair<int, int> >(3, {0, 0}));
        vector<pair<int, int> > st, nd, th;
        int stn = 0, ndn = 0, thn = 0;
        for(int i = 0; i < n; i++) {
            int znum = 0;
            for(int j = 0; j < 3; j++) {
                int dd; scanf("%d", &dd);
                if(dd == 0) znum++;
                a[i][j] = {dd, j+1};
            }
            sort(a[i].begin(), a[i].end());
            if(znum >= 2) {
                ans += a[i][2].first;
                if(a[i][2].second == 1 && stn < n/2) stn++;
                else if(a[i][2].second == 2 && ndn < n/2) ndn++;
                else if(a[i][2].second == 3 && thn < n/2) thn++;
                continue;
            }
            if(a[i][2].second == 1) st.push_back({a[i][2].first - a[i][1].first, i});
            else if(a[i][2].second == 2) nd.push_back({a[i][2].first - a[i][1].first, i});
            else th.push_back({a[i][2].first - a[i][1].first, i});
        }
        sort(st.begin(), st.end(), cmp);
        sort(nd.begin(), nd.end(), cmp);
        sort(th.begin(), th.end(), cmp);
        if((int)st.size() > n/2) {
            for(size_t i = 0; i < st.size(); i++) {
                if(stn < n/2) ans += a[st[i].second][2].first, stn++;
                else ans += a[st[i].second][1].first;
            }
            for(size_t i = 0; i < nd.size(); i++) ans += a[nd[i].second][2].first;
            for(size_t i = 0; i < th.size(); i++) ans += a[th[i].second][2].first;
        }
        else if((int)nd.size() > n/2) {
            for(size_t i = 0; i < nd.size(); i++) {
                if(ndn < n/2) ans += a[nd[i].second][2].first, ndn++;
                else ans += a[nd[i].second][1].first;
            }
            for(size_t i = 0; i < st.size(); i++) ans += a[st[i].second][2].first;
            for(size_t i = 0; i < th.size(); i++) ans += a[th[i].second][2].first;
        }
        else if((int)th.size() > n/2) {
            for(size_t i = 0; i < th.size(); i++) {
                if(thn < n/2) ans += a[th[i].second][2].first, thn++;
                else ans += a[th[i].second][1].first;
            }
            for(size_t i = 0; i < st.size(); i++) ans += a[st[i].second][2].first;
            for(size_t i = 0; i < nd.size(); i++) ans += a[nd[i].second][2].first;
        }
        else if(stn == n/2) {
            for(size_t i = 0; i < st.size(); i++) {
                if(a[st[i].second][1].second == 2) nd.push_back({0, st[i].second});
                else ans += a[st[i].second][1].first;
            }
            for(size_t i = 0; i < nd.size(); i++) ans += a[nd[i].second][2].first;
            for(size_t i = 0; i < th.size(); i++) ans += a[th[i].second][2].first;
        }
        else if(ndn == n/2) {
            for(size_t i = 0; i < nd.size(); i++) {
                if(a[nd[i].second][1].second == 1) st.push_back({0, nd[i].second});
                else ans += a[nd[i].second][1].first;
            }
            for(size_t i = 0; i < st.size(); i++) ans += a[st[i].second][2].first;
            for(size_t i = 0; i < th.size(); i++) ans += a[th[i].second][2].first;
        }
        else if(thn == n/2) {
            for(size_t i = 0; i < th.size(); i++) {
                if(a[th[i].second][1].second == 1) st.push_back({0, th[i].second});
                else ans += a[th[i].second][1].first;
            }
            for(size_t i = 0; i < st.size(); i++) ans += a[st[i].second][2].first;
            for(size_t i = 0; i < nd.size(); i++) ans += a[nd[i].second][2].first;
        }
        else {
            for(size_t i = 0; i < st.size(); i++) ans += a[st[i].second][2].first;
            for(size_t i = 0; i < nd.size(); i++) ans += a[nd[i].second][2].first;
            for(size_t i = 0; i < th.size(); i++) ans += a[th[i].second][2].first;
        }
        printf("%d\n", ans);
    }

    return 0;
}
