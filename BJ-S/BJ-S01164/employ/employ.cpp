#include<bits/stdc++.h>
#define MOD 998244353
using namespace std;
int c[505], id[505];
bool check(string s){
    for (int i = 0; i < s.size(); i++){
        if (s[i] == '0') return 0;
    }
    return 1;
}
int main(){
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    int n, m; cin >> n >> m;
    string s; cin >> s;
    for (int i = 1; i <= n; i++){
        cin >> c[i];
        id[i] = i;
    }
    int ans = 0;
    if (m == n){
        for (int i = 1; i <= n; i++){
            if (s[i - 1] == '0' || !c[i]){
                cout << 0 << endl;
                return 0;
            }
        }
        long long ans = 1;
        for (long long i = 1; i <= n; i++){
            ans = (ans * i) % MOD;
        }
        cout << ans << endl;
        return 0;
    }
    if (check(s)){
        long long ans = 1;
        for (long long i = 1; i <= n; i++){
            ans = (ans * i) % MOD;
        }
        cout << ans << endl;
        return 0;
    }
    do{
        int cnt1 = 0, cnt2 = 0;
        for (int i = 1; i <= n; i++){
            if (s[i - 1] == '0') cnt1++;
            else{
                if (c[id[i]] > cnt1) cnt2++;
                else cnt1++;
            }
        }
        if (cnt2 >= m) ans = (ans + 1) % MOD;
    }while(next_permutation(id + 1, id + n + 1));
    cout << ans << endl;
    return 0;
}
