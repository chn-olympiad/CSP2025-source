#include<bits/stdc++.h>
#define ll long long

using namespace std;
int jie_cheng_n[5050];
const ll inf = 998244353;
int a[5050], n;
int txt = 0;
ll ans = 0;
int c[5050];
inline void dfs(int x, int ma, ll sum)
{
    if(x > n)
    {
        if(txt < 3)
            return;
        if(ma * 2 < sum)
        {
            //cout << "sum=" << sum << ' ';
            /*for(int i = 1; i<= n;i++)
            {
                cout<<c[i]<<' ';
            }
            cout<<endl;*/
            ans = (ans + 1) % inf;
        }
        return;
    }
    //chose x
    c[x] = 1;
    int la_ma = ma;
    ma = a[x];
    sum += a[x];
    txt++;
    //c[x] = 1
    dfs(x + 1, ma, sum);
    ma = la_ma;
    sum -=a[x];
    txt--;
    c[x] = 0;
    //did not chose x
    dfs(x + 1, ma, sum);
}

int main()
{
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    int maaa = -10086;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        maaa = max(maaa, a[i]);
    }
    sort(a + 1, a + n + 1);

    /**/if(maaa == 1)
    {

        jie_cheng_n[1] = 1;
        jie_cheng_n[0] = 1;
        for(int i = 2; i <= n; i++)
        {
            jie_cheng_n[i] = jie_cheng_n[i - 1] * i % inf;

        }
        int anss = 0;
        for(int i = 3; i <= n; i++)
        {
            anss = (anss + (jie_cheng_n[n] / jie_cheng_n[n - i])/jie_cheng_n[i] % inf);
            //cout << (jie_cheng_n[n] / jie_cheng_n[n - i])/jie_cheng_n[i] % inf<< endl;
        }
        cout << anss;
        return 0;
    }
    dfs(1, 0, 0);
    cout << ans;
    return 0;
}
