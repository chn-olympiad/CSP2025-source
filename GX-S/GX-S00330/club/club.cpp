#include<iostream>
#include<cstring>
using namespace std;
#define ll long long

const int N = 1e5 + 10;
int a[N] = {};
int b[N] = {};
int c[N] = {};
int dan[N] = {};
int t, n;
bool vis[N] = {};
ll ans = 0;
int A, B, C;
void dfs(int k) {
    if (k == n) {
        ll res = 0;
        for (int i=0;i<n;i++) {
            res += dan[i];
        }
        ans = max(res, ans);
    }
    else {
        if (A > 0) {
            A--;
            dan[k] = a[k];
            dfs(k+1);
            A++;
        }
        if (B>0) {
            B--;
            dan[k] = b[k];
            dfs(k+1);
            B++;
        }
        if (C>0) {
            C--;
            dan[k] = c[k];
            dfs(k+1);
            C++;
        }
    }
}


int main() {
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> t;
    while (t--) {
        ans = 0;
        cin >> n;
        for (int i=0;i<n;i++) {
            cin >> a[i] >> b[i] >> c[i];
        }
        A = n/2;
        B = n/2;
        C = n/2;
        dfs(0);
        cout << ans << '\n';
    }
    return 0;
}
