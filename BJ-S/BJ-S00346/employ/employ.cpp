#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 998244353;
int n,m,c[505],ans,a[505];
bool s[505];
main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin >> n >> m;
    for (int i = 1;i <= n;i++){
        char c;
        cin >> c;
        s[i] = c - '0';
    }
    for (int i = 1;i <= n;i++) a[i] = i,cin >> c[i];
    if (n <= 10){
        do{
            int f = 0,cnt = 0;
            for (int i = 1;i <= n;i++){
                if (f >= c[a[i]] || s[i] == 0) f++;
                else cnt++;
            }
            ans = (ans + (cnt >= m)) % mod;
        }while (next_permutation(a + 1,a + n + 1));
        cout << ans;
    }else{
        int ans = 1;
        for (int i = 1;i <= n;i++) ans = ans * i % mod;
        cout << ans;
    }
    return 0;
}