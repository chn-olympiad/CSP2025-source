#include <bits/stdc++.h>
using namespace std;
struct node
{
    int e;
    int s;
};
node a[10001];
string t[1001];
string fxor(string a, string b)
{
    for (int i = 0; i < 20; i++)
    {
        if (a[i] == b[i])
        {
            a[i] = '0';
        }
        else
        {
            a[i] = '1';
        }
    }
    return a;
}
string to2 (int n)
{
    string s;
    //cout << n << endl;
    while(n != 0)
    {
        //cout << n << endl;
        s = char(n % 2 + '0') + s;
        n /= 2;
    }
    while (s.size() != 20)
    {
        s = "0" + s;
    }
    return s;
}
bool cmp(node a, node b)
{
    return a.e < b.e;
}
int dp[1000];
int main ()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    int n, s;
    cin >> n >> s;
    //cout << to2(0) << endl;
    string k = to2(s);
    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        int tmp;
        cin >> tmp;
        t[i] = to2(tmp);
        //cout << t[i] << endl;
        string m = t[i];
        if (m == k)
        {
            //cout << cnt << " " << i << " " << i << endl;
            a[++cnt].s = i;
            a[cnt].e = i;
        }
        for (int j = i - 1; j >= 1; j--)
        {
            m = fxor(m, t[j]);
            if (m == k)
            {
                //cout << cnt << " " << j << " " << i << endl;
                a[++cnt].s = j;
                a[cnt].e = i;
            }
        }
    }
    sort (a + 1, a + cnt + 1, cmp);
    int ni = 1;
    for (int i = 1; i <= n; i++)
    {
        while (a[ni].e == i)
        {
            dp[i] = max(dp[i], dp[a[ni].s - 1] + 1);
            ni++;
        }
        dp[i] = max(dp[i], dp[i - 1]);
    }
    cout << dp[n] << endl;
    return 0;
}
// 60pts
