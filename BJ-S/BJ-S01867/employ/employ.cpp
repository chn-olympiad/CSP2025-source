#include <bits/stdc++.h>
using namespace std;
const long long MOD=998244353;

char s[505];
long long n, m, ans=0, c[505];
void dfs(long long k, long long p, long long x, long long v){
    if(x == (1 << n)-1){
        // cout << v << "\n";
        if(v >= m) ans++;
        return;
    }
    for(long long i=1;i <= n;i++){
        if(((x >> (i-1)) & 1) == 0){
            if(s[k] == '0' || p >= c[i]) dfs(k+1, p+1, x+(1 << (i-1)), v);
            else dfs(k+1, p, x+(1 << (i-1)), v+1);
        }
    }
}
int main(){
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    cin >> n >> m;
    if(n > 18){
        cout << 0;
        return 0;
    }
    else{
        for(long long i=1;i <= n;i++){
            cin >> s[i];
        }
        for(long long i=1;i <= n;i++){
            cin >> c[i];
        }
        dfs(1, 0, 0, 0);
        cout << ans;
    }
    return 0;
}