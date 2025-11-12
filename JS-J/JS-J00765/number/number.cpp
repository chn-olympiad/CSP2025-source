#include <bits/stdc++.h>
#define int long long
#define rep(i, n) for(int i = 1; i <= n; i++)
using namespace std;
const int N = 2e5 + 10, INF = 9e18;
string s;
int cnt[15];
signed main(){
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> s;
    for(int i = 0; i < s.length(); i++){
        if('0' <= s[i] && s[i] <= '9'){
            cnt[s[i] - '0']++;
        }
    }
    for(int i = 9; i >= 0; i--){
        while(cnt[i]){
            cout << i;
            cnt[i]--;
        }
    }

    return 0;
}

