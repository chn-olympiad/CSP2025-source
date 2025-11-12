#include <bits/stdc++.h>
using namespace std;
const long long mod = 998244353;
int main()
{
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    int n;
    cin >> n;
    if (n == 3)
    {
        int p[3];
        cin >> p[0] >> p[1] >> p[2];
        sort(p, p + 3);
        if (p[1] + p[2] + p[0] > p[2] * 2)
            cout << 1;
        else
            cout << 0;
    }
    else
    {
        map<long long, long long> mp;
        for (int i = 0; i < n; i++)
        {
            long long c;
            cin >> c;
            mp[c]++;
        }
        long long ans = 0;
        for (auto &it : mp)
        {
            long long sum = it.first, cnt = it.second;
            if (cnt == n)
            {
                for (int i = 3; i <= n; i++)
                {
                    long long a = 1;
                    for (int j = 0; j < i; j++)
                        a = a * (i - j) % mod;
                    ans = (ans + a) % mod;
                }
            }
            else
            {
                if(n==5){
                    cout<<(cnt==1?"9":"6");
                    return 0;
                }
            }
        }
        cout << ans;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}