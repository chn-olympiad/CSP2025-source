#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    string s;
    vector<int> cnt;
    cin >> s;
    for(int i = 0; i < s.size(); i++)
    {
        if(s[i] - '0' >= 0 && s[i] - '0' <= 9)
        {
            cnt.push_back(s[i] - '0');
        }
    }
    sort(cnt.begin(), cnt.end(), greater<int>());
    for(int i = 0; i < cnt.size(); i++)
    {
        cout << cnt[i];
    }
    cout << "\n";

    return 0;
}
