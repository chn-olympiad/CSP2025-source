#include <bits/stdc++.h>
#define int long long 

using namespace std;

int a[1145];

signed main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);

    string s;
    cin >> s;
    int len = s.size();
    s = " " + s;

    for(int i = 1; i <= len; i++){
        int p = s[i];
        a[p]++;
    }

    int st = '9', ed = '0';
    for(int i = st; i >= ed; i--){
        int j = a[i], k = i - ed;
        for(int l = 1; l <= j; l++){
            cout << k;
        }
    }
    cout << endl;

    return 0;
}