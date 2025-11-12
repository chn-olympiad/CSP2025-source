#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
using pi = pair<int, int>;
const int N = 100005;
const ll inf = 0x3f3f3f3f3f3f3f3f;
int n, lmt;
ll a[N][3], cnt[3], ans;
vector<int> gx[3];

void solve()
{
    cin >> n;
    lmt = n / 2;
    for(int i = 0; i < 3; i++)
    {
        gx[i].clear();
        cnt[i] = 0;
    }
    ans = 0;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i][0] >> a[i][1] >> a[i][2];
        ll mxv = max(a[i][0], max(a[i][1], a[i][2]));
        if(a[i][0] == mxv)
        {
            gx[0].push_back(mxv - max(a[i][1], a[i][2]));
            cnt[0]++;
        }
        else if(a[i][1] == mxv)
        {
            gx[1].push_back(mxv - max(a[i][0], a[i][2]));
            cnt[1]++;
        }
        else
        {
            gx[2].push_back(mxv - max(a[i][0], a[i][1]));
            cnt[2]++;
        }
        ans += mxv;
    }
    for(int i = 0; i < 3; i++)
    {
        sort(gx[i].begin(), gx[i].end());
        if(cnt[i] > lmt)
        {
            int j = 0;
            while(cnt[i] > lmt)
            {
                cnt[i]--;
                ans -= gx[i][j];
                j++;
            }
        }
    }
    cout << ans << "\n";
}

int main()
{
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}