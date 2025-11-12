#include <bits/stdc++.h>
using namespace std;
string s;
int w;
char a[100005];
bool cmp(char x, char y)
{
    return x > y;
}
int main()
{
    freopen(number.in, "r", stdin);
    freopen(number.out, "w", stdout);
    cin >> s;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] >= '0' && s[i] <= '9') {
            a[i] = s[i];
            w++;
        }
    }
    sort(a, a + w, cmp);
    for (int i = 0; i < w; i++)
        cout << a[i];
    return 0;
}
