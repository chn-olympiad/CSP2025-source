#include <bits/stdc++.h>
using namespace std;

string s;
int a[10005];

int main()
{
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);

    cin >> s;
    int len = s.length();
    int j = 0;
    for (int i = 0; i <= len; i++)
    {
        // 判断是否为数字
        if (s[i] >= '0' && s[i] <= '9')
        {
            a[j] = s[i] - 48;
            j++;
        }
    }

    // 倒叙排序
    sort(a, a + j);

    for (int i = j - 1; i >= 0; i--)
    {
        cout << a[i];
    }

    return 0;
}
