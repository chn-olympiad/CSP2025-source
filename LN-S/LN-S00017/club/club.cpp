#include<bits/stdc++.h>
using namespace std;
#define up(s, e, i) for (int i = (s); i <= (e); i++)
#define down(s, e, i) for (int i = (s); i >= (e); i--)
#define all(x) x.begin(), x.end()
#define endl '\n'

namespace Main
{
    const int N = 100010;
    int n, a[N][4];
    int cnt[4];
    void solve()
    {
        cin >> n;
        up(1, 3, i) cnt[i] = 0;
        up(1, n, i) up(1, 3, j) cin >> a[i][j];
        int ans = 0;
        vector<int> d;
        up(1, n, i)
        {
            vector<int> vec = {1, 2, 3};
            sort(all(vec), [&](int x, int y) { return a[i][x] > a[i][y]; });
            ans += a[i][vec[0]];
            cnt[vec[0]]++;
        }
        int mx = max({cnt[1], cnt[2], cnt[3]});
        if (mx > n / 2)
        {
            int pos = 1;
            up(2, 3, i) if (cnt[i] == mx) pos = i;
            up(1, n, i)
            {
                vector<int> vec = {1, 2, 3};
                sort(all(vec), [&](int x, int y) { return a[i][x] > a[i][y]; });
                if(vec[0] == pos) d.push_back(-a[i][vec[0]] + a[i][vec[1]]);
            }
            sort(all(d));
            int X = mx - n / 2;
            while(X--)
            {
                ans += d.back();
                d.pop_back();
            }
        }
        cout << ans << endl;
    }
    void main()
    {
        freopen("club.in", "r", stdin);
        freopen("club.out", "w", stdout);
        ios::sync_with_stdio(0);
        cin.tie(0), cout.tie(0);

        int T;
        cin >> T;
        while(T--) solve();
    }
};

int main()
{
    Main::main();
    return 0;
}

// g++ club.cpp -o club -O2 -std=c++14 && ./club