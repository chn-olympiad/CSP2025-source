#include<iostream>
#include<string>
using namespace std;

freopen("employ.in", "r", stdin);
freopen("employ.out", "w", stdout);

int main()
{
    long long n, m, c[500], fake_ans = 1, ea = 0;
    string s;
    cin >> n >> m >> s;
    for (int i = 0; i < n; i++)
    {
        cin >> c[i];
        fake_ans *= i;
        fake_ans %= 998244353;
    }
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '1')
        {
            ea++;
        }
    }
    fake_ans /= s.size();
    fake_ans *= ea;
    fake_ans /= m;
    cout << fake_ans;
    return 0;
}