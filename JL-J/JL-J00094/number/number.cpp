#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
string s;
vector<int> str;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin >> s;
    int u = 0;
    for (int i = 0;i < s.size();i ++)
    {
        if (isdigit(s[i]))
        {
            str.push_back(s[i] - '0');
        }
    }
    sort(str.begin(),str.end());
    while (str.size() >= 1 && str.back() == 0)
    {
        str.pop_back();
    }
    for (int i = str.size() - 1;i >= 0;i --)
    {
        cout << str[i];
    }
    return 0;
}
