#include<bits/stdc++.h>
using namespace std;
char a[1000006];
int pos = 0;
int main()
{
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    string s;
    cin >> s;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i]<='9' && s[i]>='0') a[++pos] = s[i];
    }
    sort (a+1, a+pos+1);
    for (; pos > 0; pos--)
    {
        cout << a[pos];
    }
    return 0;
}
