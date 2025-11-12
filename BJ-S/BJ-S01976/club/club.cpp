# include <bits/stdc++.h>
# define int long long
using namespace std;
const int N = 1e5 + 5;
//my last csp s
int a[N][3];
int cnt[3];
int mx[N];
int idx[N];
vector <int> x;
void solve()
{
    int n;
    cin >> n;
    cnt[0] = cnt[1] = cnt[2] = 0;
    int ans = 0;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i][0] >> a[i][1] >> a[i][2];
        mx[i] = max({a[i][0], a[i][1], a[i][2]});
        ans += mx[i];
        for(int j = 0; j < 3; j++)
        {
            if(a[i][j] == mx[i])
            {
                cnt[j]++;
                idx[i] = j;
                break;
            }
        }
    }
    int id = -1;
    x.clear();
    for(int i = 0; i < 3; i++)
        if(cnt[i] > n / 2)
            id = i;
    //cout << cnt[0] << " " << cnt[1] << " " << cnt[2] << endl;

    if(id == -1)
    {
        //cout <<"llrllr";
        cout << ans << endl;
        return;
    }
    int k = cnt[id] - n / 2;
    //cout <<k << endl;
    for(int i = 1; i <= n; i++)
    {
        if(idx[i] != id) continue;
        int qwq = 1e18;
        for(int j = 0; j < 3; j++)
        {
            if(j != id)
            {
                qwq = min(qwq, mx[i] - a[i][j]);
            //cout << mx[i] - a[i][j] << endl;
            }
        }
        x.push_back(qwq);
    }
    sort(x.begin(), x.end());
    //for(int i = 0; i < x.size(); i++) cout << x[i] << endl;
    //cout << ans << endl;
    for(int i = 0; i < k; i++) ans -= x[i];
    cout << ans << endl;
}
signed main()
{
    ios::sync_with_stdio(0);
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    int T;
    cin >> T;
    while(T--) solve();
    return 0;
}
