#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

signed main()
{
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string str;
    getline(cin, str);
    vector<int> num;
    int sl = str.size();
    for (int i = 0; i < sl; i++)
    {
        if ('0' <= str[i] && str[i] <= '9')
        {
            num.push_back(str[i] - '0');
        }
    }
    int nl = num.size();
    sort(num.begin(), num.end(), greater<int>());
    for (int i = 0; i < nl; i++)
    {
        cout << num[i];
    }
    cout << endl;
    return 0;
}