#include<bits/stdc++.h>
typedef long long ll;
// #define int long long
#define pii pair<int, int>
#define fi first
#define se second
using namespace std;
const int N = 1e5 + 5;
int n, a[N][3], cnt[3];
vector<int> vec[3];
void SOLVE() {
    int ans = 0;
    cin>>n;
    cnt[0] = cnt[1] = cnt[2] = 0;
    vec[0].clear(), vec[1].clear(), vec[2].clear();
    for(int i = 1; i <= n; i++) {
        cin>>a[i][0]>>a[i][1]>>a[i][2];
        if(a[i][0] >= a[i][1] && a[i][0] >= a[i][2]) {
            cnt[0]++, ans += a[i][0];
            vec[0].push_back(max(a[i][1], a[i][2]) - a[i][0]);
        } else if(a[i][1] >= a[i][0] && a[i][1] >= a[i][2]) {
            cnt[1]++, ans += a[i][1];
            vec[1].push_back(max(a[i][0], a[i][2]) - a[i][1]);
        } else {
            cnt[2]++, ans += a[i][2];
            vec[2].push_back(max(a[i][0], a[i][1]) - a[i][2]);
        }
    }
    if(cnt[0] > n / 2) {
        sort(vec[0].begin(), vec[0].end(), greater<int>());
        for(int i = 0; i < cnt[0] - n / 2; i++) ans += vec[0][i];
    } else if(cnt[1] > n / 2) {
        sort(vec[1].begin(), vec[1].end(), greater<int>());
        for(int i = 0; i < cnt[1] - n / 2; i++) ans += vec[1][i];
    }  else if(cnt[2] > n / 2) {
        sort(vec[2].begin(), vec[2].end(), greater<int>());
        for(int i = 0; i < cnt[2] - n / 2; i++) ans += vec[2][i];
    }
    cout<<ans<<'\n';
}
int main() {
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t = 1; cin>>t;
    while(t--) SOLVE();
    cerr<<clock() * 1.0 / CLOCKS_PER_SEC<<'\n';
    return 0;
}
//g++ -o -std=c++14 -O2 -DddxrS; ./