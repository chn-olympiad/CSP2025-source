#include <bits/stdc++.h>
#define int long long
using namespace std;
map<int, int> mp;
signed main() {
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    string s;
    cin >> s;
    int l = s.size();
    for(int i = 0; i < l; i++)
        if(s[i] >= '0' && s[i] <= '9')
            mp[s[i] - '0']++;
    for(int i = 9; i >= 0; i--)
        for(int j = 1; j <= mp[i]; j++)
            cout << i;
    return 0;                
}
/*
rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++
rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++
rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++
rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++
rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++
rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++
rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++
rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++
rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++
rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++
rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++
rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++
rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++
rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++
rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++
rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++
rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++
rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++
*/
