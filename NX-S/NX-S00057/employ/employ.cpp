#include<bits/stdc++.h>
using namespace std;
const int MAX = 1e5+5;
const int MOD = 998244353;

map<int, int> mp;
int m[505], q[505];
int main()
{
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);

    int n, m, c[505];
    cin >> n >> m;
    string s; cin >> s;
    for(int i=1; i<=n; i++) cin >> c[i];
    sort(c+1, c+1+n);
    // for(int i=1; i<=n; i++)
    //     m[c[i]] ++;
    // q[0] = m[0];
    // for(int i=1; i<=500; i++)
    //     q[i] = q[i-1] + m[i];
    long long ans = 1;
    for(int i=1; i<=n; i++) 
        if(c[i] != 0) ans *= c[i], ans %= MOD;
    cout << ans;
    return 0;
}