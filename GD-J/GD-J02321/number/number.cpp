#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 1e6 + 50;

int n, t[maxn];
string s;

int main(){
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> s;
    n = s.size(), s = " " + s;
    for(int i = 1; i <= n; i++){
        if('0' <= s[i] && s[i] <= '9') t[s[i] - '0']++;
    }
    for(int i = 9; i >= 0; i--){
        while(t[i]--) cout << i;
    }
    return 0;
}
