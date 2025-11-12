#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 10;

char s[N];
int num[N];

int main()
{
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);

    scanf("%s", s);
    int len = strlen(s);

    int n = 0;
    for (int i = 0; i < len; i ++ )
        if (isdigit(s[i]))
            num[n ++ ] = s[i] - '0';

    sort(num, num + n, greater<int>());

    for (int i = 0; i < n; i ++ ) printf("%d", num[i]);

    return 0;
}
