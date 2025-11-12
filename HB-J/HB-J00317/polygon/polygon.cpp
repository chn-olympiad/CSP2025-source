#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;
#define int long long
const int N = 6e3+7, MOD=998244353;

int n;
int a[N], res, mx=-1;
vector<int> q;

void f(int x, int cnt)
{
    if (x > n) return;

    if (cnt > a[x]*2 && x)
    {

        res++;
        res %= MOD;
    }


    for (int i = x+1; i <= n; i++)
    {
        cnt += a[i];
        f(i, cnt);
        cnt -= a[i];
    }
}

signed main()
{
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    bool ifsp = true;
    cin >> n;
    for (int i =1; i <= n; i++)
    {
        cin >> a[i];
        if (ifsp && a[i] != 1) ifsp = false;
    }
    if (ifsp)
    {
        if (n == 1 || n == 2)
        {
            cout << 0;
            return 0;
        }
        int cnt = 0;
        for (int i = 3; i <= n; i++)
        {
            int C = 1;
            for (int j = 4; j <= i; j++)
            {
                C *= j;
                C %= MOD;
            }
            C %= MOD;
            for (int j = i-3; j >= 2; j--)
            {
                C /= j;
                C %= MOD;
            }
            q.push_back(C);
        }
        for(int i = 0; i < q.size(); i++)
        {
            for (int j = 0; j < i; j++)
            {
                q[i] += q[j];
                q[i] %= MOD;
            }
        }
        cout << q[q.size()-1]%MOD;
        return 0;
    }

    sort(a+1, a+n+1);

    f(0, 0);
    cout << res%MOD;




    return 0;
}
