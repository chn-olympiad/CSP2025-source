#include <bits/stdc++.h>
using namespace std;
#define int long long

const int mod = 998244353;
const int N = 505;

int n, m,ans;
char s[N];
int c[N];
int a[N],fl[N];

void dfs(int x) {
    if (x > n) {
        int cnt = 0, sum = 0;
        for (int i = 1; i <= n; i++) {
            if (cnt >= c[a[i]]) {
                cnt++;
                continue;
            }
            if (s[i] == '0') {
                cnt++;
                continue;
            }
            sum++;
        }
        if (sum >= m) ans++;
    }
    for (int i = 1; i <= n; i++) {
        if (fl[i]) continue;
        fl[i] = 1;
        a[x] = i;
        dfs(x + 1);
        a[x] = 0;
        fl[i] = 0;
    }
}

signed main() {
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n >> m;
    cin >> (s + 1);
    for (int i = 1; i <= n; i++)
        cin >> c[i];
    int fl = 1;
    for (int i = 1; i <= n; i++)
        if (s[i] == '0') fl = 0;
    if(m==n){
        if(!fl){
            cout<<"0\n";
            return 0;
        }
        for(int i=1;i<=n;i++)
            if(!c[i]){
                cout<<"0\n";
                return 0;
            }
        int ans = 1;
        for (int i = 1; i <= n; i++)
            ans = ans * i % mod;
        cout << ans << '\n';
        return 0;
    }
    dfs(1);
    cout<<ans;
    //sort(c + 1, c + n + 1);
    return 0;
}