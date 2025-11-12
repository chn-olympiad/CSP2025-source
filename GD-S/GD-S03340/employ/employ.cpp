#include<bits/stdc++.h>
using namespace std;
#define int long long
int n, m;
// #define DEBUG
// int n, m;
string s;
int id[2000000  + 10];
int c[2000000 + 10];
signed main(){
    #ifndef DEBUG
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    #endif 
    ios::sync_with_stdio(false);
    cin >> n >> m >> s;
    if(s.find("0") == -1){
        int res = 1;
        for(int i = 1 ; i <= n ; i++)
            res = res * i % 998244353;
        cout << res << endl;
        return 0;
    }
    int ans = 0;
    for(int i = 1 ; i <= n ; i++) cin >> c[i], id[i] = i;
    do{
        int tot = 0;
        for(int i = 1 ; i <= n ; i++){
            if(!(s[i - 1] == '0' || i - tot - 1 >= c[id[i]]))
                tot++;
        }
        if(tot >= m)
            ans++;
    }while(next_permutation(id + 1, id + 1 + n));
    cout << ans << endl;
    return 0;
}