#include <bits/stdc++.h>

using namespace std;

priority_queue<int> arr;
int main()
{
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);

    string s;
    cin >> s;
    int cnt = 0;
    for (int i = 0; i < s.size(); i++)
      if (s[i] - '0' >= 0 && s[i] - '0' <= 9)
        arr.push(s[i] - '0');
    if (arr.empty())
    {
        cout << 0;
        return 0;
    }
    while (!arr.empty())
    {
        cout << arr.top();
        arr.pop();
    }

    return 0;
}
