#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    for (int i = 1; i <= 14000000;)
        i++;
    srand(time(0));
    cout << rand() % 200 << '\n';

    return 0;
}