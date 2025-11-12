#include <iostream>
#include <vector>
#include <algorithm>
#define int long long
#define endl "\n"
using namespace std;

vector<int> num;

signed main()
{
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    string s;
    cin >> s;
    for (char c : s)
    {
        if (isdigit(c))
        {
            num.push_back(c - '0');
        }
    }
    sort(num.begin(), num.end(), greater<int>());
    for (int i : num)
    {
        cout << i;
    }
    cout << endl;
    return 0;
}