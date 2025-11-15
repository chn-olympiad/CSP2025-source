#include <bits/stdc++.h>
using namespace std;

ifstream fin("employ.in");
ofstream fout("employ.out");

bool chk_A(string s) {
    int n = s.size();
    for (int i = 0; i < n; ++i) {
        if (s[i] != '1') {
            return false;
        }
    }
    return true;
}

int solve(string s, vector<int>& a) {
    int n = s.size(), dead = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '0' || dead >= a[i]) {
            ++dead;
        }
    }
    return n - dead; // no. of ppl hired
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n, m;
    fin >> n >> m;

    string s;
    fin >> s;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        fin >> a[i];
    }

    map<int, int> cnt;
    for (int i : a) {
        ++cnt[i];
    }
    int mult = 1;
    for (pair<int, int> p : cnt) {
        mult *= p.second;
    }

    sort(a.begin(), a.end());
    int ans = 0;
    do {
        if (solve(s, a) >= m) {
            ++ans;
        }
    } while (next_permutation(a.begin(), a.end()));

    fout << ans * mult << '\n';
}