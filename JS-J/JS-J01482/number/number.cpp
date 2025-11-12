#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 10;
int res[N];

int main()
{
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);

    string str;
    cin >> str;

    int cnt = 0;
    for (int i = 0; i < str.size(); i ++ )
    {
        char c = str[i];
        if (c >= '0' && c <= '9')
            res[cnt ++ ] = c - '0';
    }

    sort(res, res + cnt, [](int a, int b) { return a > b; });

    for (int i = 0; i < cnt; i ++ )
        printf("%d", res[i]);

    return 0;
}
