#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("number.in", "r", stdin);
    freopen("number.in", "r", stdin);
    string s;
    cin >> s;
    vector<int> p(10, 0);
    for (auto &it : s)
        p[it - '0']++;
    for (int i = 9; i >= 0; i--)
    {
        while (p[i] > 0)
        {
            cout << i;
            p[i]--;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}