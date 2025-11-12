#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 505, mod = 998244353;

int n, m, c[maxn], a[maxn], flag, ct0, p[maxn], ans;
string s;

int main(){
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> m >> s, s = " " + s;
    int fact = 1;
    for(int i = 1; i <= n; i++){
        cin >> c[i];
        a[i] = (s[i] == '1'), flag += a[i];
        if(!c[i]) ct0++;
        p[i] = i, fact = 1ll * fact * i % mod;
    }
    // cerr << flag << ' ' << endl;
    if(n <= 10){
        do{
            int r = 0, w = 0;
            for(int i = 1; i <= n; i++){
                if(!a[i] || w >= c[p[i]]) w++;
                else r++;
            }
            if(r >= m){
                // for(int i = 1; i <= n; i++) cerr << p[i] << ' ';
                // cerr << endl;
                ans++;
            }
        } while(next_permutation(p + 1, p + n + 1));
        cout << ans;
    } else if(flag == n && !ct0) cout << fact;
    else cout << 0;
    return 0;
}