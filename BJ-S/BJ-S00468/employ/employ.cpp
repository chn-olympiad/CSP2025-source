#include<bits/stdc++.h>
using namespace std;
const int MOD = 998244353;
int c[510];
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n,m;
    string s;
    cin >> n >> m >> s;
    int cnt = n;
    for(int i = 1;i <= n;i++){
        cin >> c[i];
        if(c[i] == 0) cnt--;
    }
    if(cnt < m) cout << 0;
    else{
        long long ans = 1;
        for(int i = 2;i <= n;i++){
            ans *= i;
            if(ans >= MOD) ans %= MOD;
        }
        cout << ans;
    }
    cout << endl;
    return 0;
}
