#include<bits/stdc++.h>
#define fi first
#define se second
#define endl '\n'
using namespace std;
using ll = long long;
using pii = pair<int,int>;
const int N = 1e5+10;
int n;
array<pii,4> a[N];
vector<int> c[4];
int cnt[4];

void solve() {
    for (int i = 1; i <= 3; i++) {
        cnt[i]=0;
        c[i].clear();
    }
    cin >> n;
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> a[i][j].fi;
            a[i][j].se=j+1;
        }
        sort(a[i].begin(),a[i].end(),greater<pii>());
        c[a[i][0].se].push_back(a[i][0].fi-a[i][1].fi);
        ans += a[i][0].fi;
        cnt[a[i][0].se]++;
    }
    int k = 0;
    for (int j = 1; j <= 3; j++) {
        if (c[j].size()>n/2) {
            k = j;
        }
    }
    if (k) sort(c[k].begin(),c[k].end());
    else {
        cout << ans << endl;
        return;
    }
    for (int i = 0; cnt[k]>n/2; i++) {
        cnt[k]--;
        ans -= c[k][i];
    }
    cout << ans << endl;
}

int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(nullptr);cout.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
