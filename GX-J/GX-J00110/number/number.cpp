#include <bits/stdc++.h>
using namespace std;

bool cmp(int x, int y)
{
    return x >y;
}

int main()
{
   freopen("number.in", "r", stdin);
   freopen("number.out", "w", stdout);

    //ios::sync_with_stdio(false);
    //cin.tie(NULL);

    vector<int> a;
    string s;
    cin >>s;
    int n = s.length();
    for (int i = 0; i < n; i++)
    {
        if ('0' <= s[i] && s[i] <= '9')
            a.push_back(s[i] - '0');
    }

    sort(a.begin(), a.end(), cmp);

    for (int i = 0; i < a.size(); i++)
        cout << a[i];
    cout << '\n';

    return 0;


}
