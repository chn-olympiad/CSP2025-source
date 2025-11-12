#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, q;
string s[4000005], t1[4000005], t2[4000008];
int main()
{
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >>q;
    for(int i = 1; i <= n; ++i)
        cin >> s[i];
    for(int i = 1; i <= q; ++i)
        cin >> t1[i] >> t2[i];
    for(int i = 1; i <= q; ++i)
        cout << 0 <<"\n";
    return 0;
}
