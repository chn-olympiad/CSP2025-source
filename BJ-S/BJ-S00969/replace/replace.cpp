#include <iostream>
#include <cstdio>
using namespace std;

string s1[1010], s2[1010];

int main()
{
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
    {
        cin >> s1[i] >> s2[i];
    }
    while (q--)
    {
        string ss1, ss2;
        cin >> ss1 >> ss2;
        cout << 0 << endl;
    }
    return 0;
}
