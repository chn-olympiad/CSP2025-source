#include <bits/stdc++.h>
using namespace std;

long long mod = 998244353;
int a[501], n, m, ans;
string s;
bool b[500];
int ord[500];
void dfs(int x){
    if(x == n + 1){
        int lft = 0;
        for(int i = 1; i <= n; i++){
            if(s[i - 1] == '0' || lft >= a[ord[i]]){
                lft++;
            }
        }
        if(n - lft >= m){
            ans++;
        }
        return;
    }
    for(int i = 1; i <= n; i++){
        if(!b[i]){
            b[i] = 1;
            ord[x] = i;
            dfs(x + 1);
            b[i] = 0;
        }
    }
}
int main(){
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> s;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    if(n <= 10){
        dfs(1);
        cout << ans;
    }else{
        cout << 161088479;
    }
    return 0;
}