#include<bits/stdc++.h>
#define int long long
using namespace std;
const int Mod = 998244353;
int n, m, c[1005];
string s;
int p[1005];
signed main(){
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    cin >> n >> m;
    cin >> s; s = " " + s;
    for(int i = 1; i <= n; i++) cin >> c[i];
    for(int i = 1; i <= n; i++) p[i] = i;
    int cnt = 0;
    do{
        int failpeople = 0, used = 0;
        for(int i = 1; i <= n; i++){
            if(failpeople < c[p[i]]){
                if(s[i] == '0') failpeople++;
                else used++;
            }else failpeople++;
        }
        if(used >= m) cnt = (cnt + 1) % Mod;
    }while(next_permutation(p + 1, p + 1 + n));
    cout << cnt << '\n';
    return 0;
}