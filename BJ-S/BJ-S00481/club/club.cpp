#include <bits/stdc++.h>
#define int long long
using namespace std;

const int NR = 1e5;
int T, n, id, tot[4], ans;
struct node
{
    int des, val;
}sec[NR + 7];
bool flag[NR + 7];

bool cmp(node x, node y)
{
    if(abs(x.des - id) != abs(y.des - id)) return abs(x.des - id) < abs(y.des - id);
    return x.val <= y.val;
}

signed main()
{
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    cin >> T;
    while(T--)
    {
        memset(flag, true, sizeof(flag));
        cin >> n;
        ans = 0;
        int b, c, d;
        int mx, mn, mid;
        int pk, valk, desk;
        tot[1] = 0, tot[2] = 0, tot[3] = 0;
        for(int i = 1; i <= n; i++)
        {
            scanf("%lld%lld%lld", &b, &c, &d);
            mx = max(b, max(c, d));
            mn = min(b, min(c, d));
            mid = b + c + d - mx - mn;
            ans += mx, sec[i].val = mx - mid;
            if(b == mx) sec[i].des = 1, tot[1]++;
            else if(c == mx) sec[i].des = 2, tot[2]++;
            else sec[i].des = 3, tot[3]++;
        }
        if(tot[1] <= n / 2 && tot[2] <= n / 2 && tot[3] <= n / 2)
        {
            cout << ans << endl;
            continue;
        }
        if(tot[1] > n / 2) id = 1;
        else if(tot[2] > n / 2) id = 2;
        else id = 3;
        sort(sec + 1, sec + n + 1, cmp);
        for(int i = 1; tot[id] > n / 2; tot[id]--, i++)
            ans -= sec[i].val;
        cout << ans << endl;
    }
    return 0;
}
