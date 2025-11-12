#include<bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pil pair<int, ll>
#define pli pair<ll, int>
using namespace std;
int n, m;
string s;
bool b[505];
int c[505];
int p[505];
int ans;
int main() {
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m >> s;
    for(int i = 1; i <= n; i++) {
        b[i] = s[i - 1] - '0';
        p[i] = i;
    }
    for(int i = 1; i <= n; i++) {
        cin >> c[i];
    }
    do {
        int cnt = 0;
        for(int i = 1; i <= n; i++) {
            if(!b[i] || cnt >= c[p[i]]) {
                cnt++;
            }
        }
        //for(int i = 1; i <= n; i++) {
        //    cout << p[i] << " ";
        //}
        //cout << ": " << n - cnt << endl;
        if(n - cnt >= m) {
            ans++;
        }
    } while(next_permutation(p + 1, p + n + 1));
    cout << ans << endl;
    return 0;
}
