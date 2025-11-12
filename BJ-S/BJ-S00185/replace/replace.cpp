#include <bits/stdc++.h>
#define int long long
using namespace std;

int n, q;
unordered_map<string, string> mp;
string x, y;
int ans;

signed main()
{
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> q;
    for(int i = 1; i <= n; i++)
        cin >> x >> y, mp[x] = y;
    while(q--)
    {
        ans = 0;
        cin >> x >> y;
        int l;
        for(l = 0; l < x.size(); l++)
            if(x[l] != y[l]) break;
        int r;
        for(r = x.size() - 1; r >= 0; r--)
            if(x[r] != y[r]) break;
        //cout << '*' << l << ' ' << r << '\n';
        for(int ll = 0; ll <= l; ll++)
            for(int rr = x.size() - 1; rr >= r; rr--)
            {
                if(mp.count(x.substr(ll, rr - ll + 1)) && mp[x.substr(ll, rr - ll + 1)] == y)
                    ans++;
            }
        cout << ans << '\n';
    }

    return 0;
}