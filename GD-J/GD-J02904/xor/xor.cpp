#include <bits/stdc++.h>
using namespace std;
long long n, k;
const long long N = 200005;
long long a[N];
//sub1 (n <= 1000)
    long long sum[1005][1005];
    long long tmp[1005];
    vector <pair <long long, long long>> vec;
    bool cmp(pair <long long, long long> x, pair <long long, long long> y)
    {
        if (x.second == y.second) return x.first < y.first;
        return x.second < y.second;
    }
//end

void sub()
{
    for (long long i = 1; i <= n; i ++)
    {
        tmp[i] = tmp[i - 1] ^ a[i];
    }
    for (long long i = 1; i <= n; i ++)
    {
        for (long long j = i; j <= n; j ++)
        {
            sum[i][j] = tmp[j] ^ tmp[i - 1];
            if (sum[i][j] == k)
            {
                vec.push_back({i, j});
            }
        }
    }
    sort(vec.begin(), vec.end(), cmp);
    long long last = 0, ans = 0;
    for (auto i : vec)
    {
        if (last < i.first)
        {
            ans ++;
            last = i.second;
        }
    }
    cout << ans;
    return;
}

//subB
void subB()
{
    if (k == 0)
    {
        long long ans = 0;
        for (long long i = 1; i <= n; i ++)
        {
            if (a[i] == 0) ans ++;
            else
            {
                if (a[i + 1] == 1)
                {
                    ans ++;
                    i ++;
                }
            }
        }
        cout << ans;
    }
    else
    {
        long long ans = 0;
        for (long long i = 1; i <= n; i ++)
        {
            if (a[i] == 0)
            {
                if (a[i + 1] == 1)
                {
                    ans ++;
                    i ++;
                }
            }
            else
            {
                if (a[i + 1] == 0)
                {
                    ans ++;
                    i ++;
                }
            }
        }
        cout << ans;
    }
    return;
}
int main()
{
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    cin >> n >> k;
    for (long long i = 1; i <= n; i ++)
    {
        cin >> a[i];
    }
    if (n <= 1000)
    {
        sub();
    }
    else if (k <= 1)
    {
        subB();
    }
    return 0;
}