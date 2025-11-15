/*
154622 finally finished debugging
155328 i hope its not ll
155841 dllm is min max

 - Rudolf Heinrich Fredrich Gottfried Ferdinand Vrydach Graf von Loringhoven
*/


#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ff first
#define ss second

vector<vector<ll>> fc(100000, vector<ll>(3));

bool cmp(ll a, ll b) {
    if (fc[a][0] == 0 && fc[b][0] == 0) {
        return max(fc[a][1], fc[a][2]) > max(fc[b][1], fc[b][2]);
    }
    if (fc[a][1] == 0 && fc[b][1] == 0) {
        return max(fc[a][0], fc[a][2]) > max(fc[b][0], fc[b][2]);
    }
    return max(fc[a][1], fc[a][0]) > max(fc[b][1], fc[b][0]);
}

pair<ll, ll> sum2p(ll a) {
    if (a == 3) {
        return {1, 2};
    }
    if (a == 2) {
        return {0, 2};
    }
    return {0, 1};
}

void solve() {
    ll n; cin >> n;
    fc.resize(n);
    ll ans = 0;
    for (ll i = 0; i < n; i++) {
        ll a, b, c; cin >> a >> b >> c;
        ll d = max(a, max(b, c));
        ans += d;
        fc[i][0] = a - d;
        fc[i][1] = b - d;
        fc[i][2] = c - d;
    }
    vector<vector<ll>> sep(3);
    for (ll i = 0; i < n; i++) {
        if (fc[i][0] == 0) {
            sep[0].push_back(i);
        } else if (fc[i][1] == 0) {
            sep[1].push_back(i);
        } else {
            sep[2].push_back(i);
        }
    }

    for (ll i = 0; i < 3; i++) {
        sort(sep[i].begin(), sep[i].end(), cmp);
        while (sep[i].size() > n / 2) {
            pair<ll, ll> f = sum2p(3 - i);
            if (fc[sep[i][0]][f.ff] > fc[sep[i][0]][f.ss]) {
                ans += fc[sep[i][0]][f.ff];
                sep[f.ff].push_back(i);
            } else {
                ans += fc[sep[i][0]][f.ss];
                sep[f.ss].push_back(i);
            }
            sep[i].erase(sep[i].begin());
        }
    }

    cout << ans << endl;
}

int main() {
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);

    ll t; cin >> t;
    while (t--) {
        solve();
    }
}