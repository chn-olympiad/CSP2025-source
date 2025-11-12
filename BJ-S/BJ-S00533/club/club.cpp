#include<bits/stdc++.h>
#define int long long
int t, n, ans; std::vector<int> Club[3];
struct person {
    std::pair<int, int> club[3];
    const bool operator < (const person& other) const {
        return (club[2].first - club[1].first) < (other.club[2].first - other.club[1].first);
    }
} p[100005];
bool cmp(int x, int y) {
    return p[x] < p[y];
}
int check() {
    int x;
    if(Club[0].size() >= Club[1].size() && Club[0].size() >= Club[2].size()) x = 0;
    else if(Club[1].size() >= Club[0].size() && Club[1].size() >= Club[2].size()) x = 1;
    else x = 2;
    if(Club[x].size() > n / 2) return x;
    return -1;
}
signed main() {
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    scanf("%lld", &t);
    while(t--) {
        ans = 0; for(int i = 0; i < 3; i++) Club[i].clear();
        scanf("%lld", &n);
        for(int i = 1; i <= n; i++) {
            for(int j = 0; j < 3; j++) {
                scanf("%lld", &p[i].club[j].first);
                p[i].club[j].second = j + 1;
            }
            std::sort(p[i].club, p[i].club + 3);
            ans += p[i].club[2].first;
            Club[p[i].club[2].second - 1].push_back(i);
        }
        int c = check();
        if(c == -1) { printf("%lld\n", ans); continue; }
        std::sort(Club[c].begin(), Club[c].end(), cmp);
        for(int i = 0; i < Club[c].size() - n / 2; i++)
            ans -= (p[Club[c][i]].club[2].first - p[Club[c][i]].club[1].first);
        printf("%lld\n", ans);
    }
}
