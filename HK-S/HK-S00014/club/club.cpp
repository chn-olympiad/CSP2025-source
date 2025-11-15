#include <bits/stdc++.h>
using namespace std;
ifstream fin ("club.in");
ofstream fout ("club.out");
int main() {
    ios_base::sync_with_stdio(false);
    fin.tie(NULL);
    int t; fin >> t;
    while (t--) {
        int n; fin >> n;
        vector<vector<pair<int, int>>> ar(n, vector<pair<int, int>> (3));
        for (auto& s : ar) {
            fin >> s[0].first >> s[1].first >> s[2].first;
            s[0].second = 0;
            s[1].second = 1;
            s[2].second = 2;
        }
        sort(ar.begin(), ar.end(), [](auto& a, auto& b){
            sort(a.begin(), a.end(), greater<pair<int, int>>());
            sort(b.begin(), b.end(), greater<pair<int, int>>());
            if (a[0].first - a[1].first != b[0].first - b[1].first) 
                return a[0].first - a[1].first > b[0].first - b[1].first;
            return a[1].first - a[2].first > b[1].first - b[2].first;
        });
        vector<int> clubs = {0, 0, 0};
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            int j = 0;
            while (clubs[ar[i][j].second] >= (n >> 1)) j++;
            ans += ar[i][j].first;
            clubs[ar[i][j].second]++;
        }
        fout << ans << '\n';
    }
}