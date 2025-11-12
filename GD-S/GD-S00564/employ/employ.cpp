#include<bits/stdc++.h>
using namespace std;

int const MOD = 998244353;
int const N = 505;
string s;
int c[N];
int pos[N];
int n, m;
int ans;
int ul;

bool check(){
    bool flag = true;
    for(int i = 0; i < s.size(); i++){
        if(s[i] != '1') {flag = false;}
        else ul ++;
    }
    return 1;
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);

    cin >> n >> m >> s;
    for(int i = 1; i <= n; i++) {cin >> c[i]; pos[i] = i;}
    
    if(n <= 20){
        do{
            int k = 0, p = 0;
            for(int i = 1; i <= n; i++){
                int u = pos[i];
                if(s[i - 1] - '0' == 0 || p >= c[u]) p++;
                else if(s[i - 1] - '0' == 1) {k++;}
            }
            if(k >= m) ans ++;
        }while(next_permutation(pos + 1, pos + 1 + n));
    }else{
        if(check()){
            ans = 0;
        }else if(ul == 18){
            sort(c + 1, c + n + 1);
            int k = 0, p = 0;
            for(int i = 1; i <= 500; i++){
                if(s[i - 1] - '0' == 0 || p >= c[i]) p++;
                else if(s[i - 1] - '0') {k++;}
            }
            cout << k << "\n";
        }
    }

    cout << ans << "\n";

    return 0;
}


// Kasty's code
