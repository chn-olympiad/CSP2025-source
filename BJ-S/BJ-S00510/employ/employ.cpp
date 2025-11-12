#include <iostream>

using namespace std;
long long n, m, a[100005], b[100005], h[100005], g[100005], ans;
const int mod = 998244353;
string s;
bool p = true;
void dfs(int step){
    if(step == n+1){
        //cout << g[1] << " " << g[2] << " " << g[3] << endl;
        int o = 0, k = 0;
        for(int i = 1;i <= n;i++){
                //cout << k << b[g[i]];
            if(b[g[i]] <= k){
                k++;
                continue;
            }
            if(a[i] == 1){
                o++;
            }
            else{
                k++;
            }
        }
    //cout << o << endl;
        if(o >= m) ans++;

        return;
    }
    for(int i = 1;i <= n;i++){
        if(h[i] == 0){
            h[i] = 1;
            g[step] = i;
            dfs(step+1);
            h[i] = 0;
        }
    }
}
int main()
{
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    cin >> n >> m;
    cin >> s;
    int f = 0;
    for(int i = 0;i < n;i++){
        a[i+1] = s[i] - '0';
        if(a[i+1] == 1 && f == 0) f = i+1;
        if(a[i+1] != 1) p = false;
    }
    for(int i = 1;i <= n;i++) cin >> b[i];
    //cout << b[1];
    if(p == true){
        long long u = 1;
        for(int i = 1;i <= n;i++){
            u *= i;
            u = u % mod;
        }
        cout << u;
        return 0;
    }
    if(n == m){
        cout << 0;
        return 0;
    }
    int cnt = 0;
    for(int i = 1;i <= n;i++){
        if(b[i] >= f) cnt++;
    }
    if(m == 1){
        long long u = 1;
        for(int i = 1;i <= n-1;i++){
            u *= i;
            u = u % mod;
        }
        u *= cnt;
        u *= mod;
        cout << u;
        return 0;
    }
    if(n <= 10){
        dfs(1);
        cout << ans;
    }
    return 0;
}
