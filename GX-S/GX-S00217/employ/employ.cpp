#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 510;
const ll MOD = 998244353;
int n,m,c[MAXN],ans;
string s;

ll fac(int x)
{
    ll res = 1;
    for (int i=2;i<=x;i++) res = (res * i) % MOD;
    return res;
}

bool pd()
{
    int une = 0,cnt = 0;
    for (int i=1;i<=n;i++)
    {
        //cout << c[i] << " ";
        if (une >= c[i])
        {
            une ++;
            continue;
        }
        if (s[i-1] == '0')
        {
            une ++;
            continue;
        }
        cnt ++;
    }
    //cout << endl;
    //cout << cnt << endl;
    return cnt >= m;
}

int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);

    cin >> n >> m >> s;
    for (int i=1;i<=n;i++) cin >> c[i];
    int facn = fac(n);
    for (int i=1;i<=facn;i++)
    {
        if (pd()) ans ++;
        std::next_permutation(c+1,c+n+1);
    }
    cout << ans << endl;

    return 0;
}
