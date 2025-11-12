#include <bits/stdc++.h>
#define int long long
#define mod 998244353
using namespace std;

int n, m;
string s;
int a[505];
int ans;

signed main()
{
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m >> s;
    bool flag = 1;
    for(char c : s)
    {
        if(c != '1') flag = 0;
    }
    for(int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1);

    if(flag)
    {
        ans = 1;
        for(int i = 1; i <= n; i++)
            ans *= i, ans %= mod;
        cout << ans;
    }
    else
    {

    do
    {
        int num = 0;
        int no = 0;
        for(int i = 1; i <= n; i++)
            if(s[i - 1] == '0' || no >= a[i]) no++;
            else num++;
        if(num >= m) ans++, ans %= mod;

    } while(next_permutation(a + 1, a + n + 1));
    cout << ans;
    }



    return 0;
}