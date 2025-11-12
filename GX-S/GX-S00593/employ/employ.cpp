#include <bits/stdc++.h>
using namespace std;
int heart[503], part[503];
bool easy = true;
int main()
{
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    ios::sync_with_stdio(false), cin.tie(0);
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    for(int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        heart[num]++;
    }
    int num = 0;
    for(int i = 0, i1 = i; i < s.size(); i++)
    {
        if(s[i] == '0' || i + 1 == s.size())
        {
            if(s[i] == '0')
                easy = false;
            part[num++] = i - i1;
            i1 = i;
        }
    }
    if(m == 1)
    {
        if(s[0] == 1)
        {
            for(int i = n - 1; i; i--)
            {
                n *= i;
                n %= 998244353;
            }
            cout << n;
            return 0;
        }
        else
        {
            cout << n;
            return 0;
        }
    }
    else if(m == n)
    {
        cout << 0;
        return 0;
    }
    else if(easy)
    {
        for(int i = n - 1; i; i--)
        {
            n *= i;
            n %= 998244353;
        }
        cout << n;
        return 0;
    }
    int ans = 1, sum = 1;
    for(int i = 0, p = 0; i < num; i++)
    {
        while(heart[p] < part[i])
        {
            if(heart[p + 1] >= part[i])
            {
                heart[p] = part[i];
                heart[p + 1] = (heart[p] + heart[p + 1] - part[i]);
                p++;
            }
            else
            {
                heart[p + 1] += heart[p];
                p++;
            }
            if(p == 501)
            {
                cout << 0;
                return 0;
            }
        }
        if(heart[p] >= m)
        {
            for(int h = heart[p]; h; h--)
                ans *= h, ans %= 998244353;
            for(int h = n - heart[p]; h; h--)
                sum *= h, sum %= 998244353;
            cout << (ans * sum) % 998244353;
            return 0;
        }
        m -= heart[p];
        for(int h = heart[p]; h; h--)
        {
            ans *= h;
            ans %= 998244353;
        }

    }
    cout << ans;
    return 0;
}
