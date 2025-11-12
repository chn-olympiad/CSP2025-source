#include <bits/stdc++.h>
using namespace std;

#define dbg(x) cerr << x << ":" << x << endl
#define dbg2(...) cerr << "[" << #__VA_ARGS__ << "] = " ,debug_out(__VA_ARGS__)

template <typename T> void debug_out(T t) { cerr << t << endl;}
template <typename T, typename  ... Ts> void debug_out(T t, Ts ... ts) {
    cerr << t << ", ";
    debug_out(ts...);

}
const int N = 1e5 + 7;
int a[N][3], b[N][3], c[N];

int main()
{
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    cin.tie(0)->sync_with_stdio(0);
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        for (int i = 1; i <= n; ++i)
        {
            cin >> a[i][0] >> a[i][1] >> a[i][2];
            b[i][0] = a[i][0], b[i][1] = a[i][1], b[i][2] = a[i][2];
            //dbg2(b[i][0], b[i][1], abs(b[i][0] - b[i][1]));
            sort(b[i], b[i] + 3);
            //dbg2(b[i][2], b[i][1]);
            c[i] = b[i][2] - b[i][1];
        }
        sort(c + 1, c + n + 1);
        //for (int i = 1; i <= n; ++i) dbg2(c[i]);
        int cnt0 = 0, cnt1 = 0, cnt2 = 0;
        long long sum = 0;
        for (int i = 1; i <= n; ++i)
        {
            if (a[i][0] >= a[i][1] && a[i][0] >= a[i][2]) cnt0++, sum += a[i][0];
            else if (a[i][1] >= a[i][0] && a[i][1] >= a[i][2]) cnt1++, sum += a[i][1];
            else cnt2++, sum += a[i][2];
        }
        //dbg2(cnt0, cnt1, cnt2, sum);
        int x = 0, y = n / 2;
        if (cnt0 > y) x = cnt0 - y;
        if (cnt1 > y) x = cnt1 - y;
        if (cnt2 > y) x = cnt2 - y;
        //dbg(x);
        for (int i = 1; i <= x; ++i) sum -= c[i];
        cout << sum << endl;
    }
    return 0;
}
