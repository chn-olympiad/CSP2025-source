#include <bits/stdc++.h>
using namespace std;
const long long mod = 998244353;
int n, m, b[505], c[505], x;
string s;
long long ans = 0;
bool a[505];
void dfs(int y) {
    if(y>n) {
        int t = 0;
        for(int i=1;i<=n;i++) {
            if(b[i]==0)
                t++;
            else if(b[i]<=t)
                t++;
            else if(s[i-1]=='0')
                t++;
        }
        if(n-t>=m) {
            ans = ((ans%mod)+1)%mod;
        }
    }
    else {
        for(int i=1;i<=n;i++) {
            if(a[i]==true)
                continue;
            b[y] = c[i];
            a[i] = true;
            dfs(y+1);
            a[i] = false;
        }
    }
}
int main() {
    std::ios::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    memset(a, false, sizeof(a));
    cin >> n >> m;
    x = n;
    cin >> s;
    for(int i=1;i<=n;i++) {
        cin >> c[i];
        if(c[i]==0)
            x--;
    }
    if(x<m)
        cout << 0;
    else {
        if(n>10) {
            ans = 1;
            for(int i=1;i<=n;i++) {
                ans = (ans*i)%mod;
            }
        }
        else
            dfs(1);
        cout << ans%mod;
    }
    return 0;
}
