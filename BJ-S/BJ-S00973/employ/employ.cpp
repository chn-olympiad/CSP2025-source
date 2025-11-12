#include <bits/stdc++.h>
using namespace std;
int c[505];
int f(int x)
{
    if (x == 2 || x == 1)
        return x;
    return x * (f(x - 1) % 998244353) % 998244353;
}
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int n,m;
    string s;
    cin >> s;
    int flag = 0,fy = 501;
    for (int i = 0;i < s.length();i++)
    {
        flag += s[i] - '0';
        if (s[i] == '1')
            fy = min(fy,i);
    }
    for (int i = 1;i <= n;i++)
    {
        int x;
        cin >> x;
        c[x]++;
    }
    if (flag == s.length())
    {
        cout << f(n) % 998244353;
    }
    else if (m == 1)
    {
        int num = 0;
        for (int i = 1;i < fy;i++)
            num += c[i];
        cout << ((num % 998244353) * (f(n - 1) % 998244353)) % 998244353;
    }
    else
    {
        cout << 0;
    }
    return 0;
}