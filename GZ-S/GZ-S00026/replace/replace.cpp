// GZ-S00026 贵阳市观山湖区普瑞学校 何景睿
#include <iostream>
#include <cstring>

using namespace std;

const int max_n = 2e5 + 1;

string s1[max_n];
string s2[max_n];

pair<int, int> b1[max_n];
pair<int, int> b2[max_n];

int read()
{
    int res = 0, neg = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9')
    {
        if (ch == '-')
            neg = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        res = res * 10 + (ch - '0');
        ch = getchar();
    }

    return res * neg;
}

int main()
{
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);

    int n = read(), q = read();

    bool k = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> s1[i] >> s2[i];

        b1[i].first = s1[i].find('b') - 1;
        b1[i].second = s1[i].length() - s1[i].find('b') - 1;
        b2[i].first = s2[i].find('b') - 1;
        b2[i].second = s2[i].length() - s2[i].find('b') - 1;
    }

    while (q--)
    {
        cin >> s1[0] >> s2[0];

        if (s1[0].find('b') > s1[0].length() || s2[0].find('b') > s2[0].length())
        {
            cout << 0 << endl;
            continue;
        }

        b1[0].first = s1[0].find('b') - 1;
        b1[0].second = s1[0].length() - s1[0].find('b') - 1;
        b2[0].first = s2[0].find('b') - 1;
        b2[0].second = s2[0].length() - s2[0].find('b') - 1;

        int ans = 0;
        for (int i = 1; i <= n; i++)
        {
            if (b1[0].first >= b1[i].first && b1[i].second <= b1[0].second)
                if (b1[0].first - b1[i].first == b2[0].first - b2[i].first && b1[0].second - b1[i].second == b2[0].second - b2[i].second)
                    ans++;
        }
        cout << ans << endl;
    }

    return 0;
}
