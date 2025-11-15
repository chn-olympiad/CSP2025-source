#include <bits/stdc++.h>
using namespace std;
ifstream fin ("employ.in");
ofstream fout ("employ.out");
int main() {
    int n, m; fin >> n >> m;
    string s; fin >> s;
    vector<pair<int, int>> ar(n);
    for (auto& s : ar) fin >> s.second;
    for (int i = 0; i < n; i++) ar[i].first = i;
    long long ans = 0;
    do {
        int ok = 0, abort = 0;
        for (int i = 0; i < n; i++) {
            if (abort >= ar[i].second || s[i] == '0') abort++;
            else ok++;
        }
        ans += (ok >= m);
    } while (next_permutation(ar.begin(), ar.end()));
    fout << ans << '\n';
}