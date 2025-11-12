#include <bits/stdc++.h>
using namespace std;

int a[10];
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);

    string s = "";
    cin >> s;
    for (int i = 0;i < s.length();i++)
    {
        int x = s[i] - '0';
        if (s[i] >= '0' && s[i] <= '9')
        {
            a[x]++;
        }
    }
    for (int i = 9;i >= 0;i--)
        for (int j = 0;j < a[i];j++)
            cout << i;
    return 0;
}
