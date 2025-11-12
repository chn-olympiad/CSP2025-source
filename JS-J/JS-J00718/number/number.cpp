#include <bits/stdc++.h>
using namespace std;

string s;
map<int, int> cnt;

int main()
{
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);

    cin >> s;
    for (char c : s)
    {
        if (c >= '0' && c <= '9') cnt[(c - '0')]++;
    }
    for (int i = 9; i >= 0; i--)
    {
        for (int j = 1; j <= cnt[i]; j++) cout << i;
    }
    cout << endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
