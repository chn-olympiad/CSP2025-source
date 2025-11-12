#include <bits/stdc++.h>

char c;
int n[140];
bool b;

int main()
{
    std::ios::sync_with_stdio(false);
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);

    while (std::cin >> c)
        n[c]++;

    for (int i = '9'; i >= '1'; --i)
        while (n[i]--)
            std::cout << char(i), b = true;
    if (!b)
        std::cout << '0';
    else
        while (n['0']--)
            std::cout << '0';

    return 0;
}
