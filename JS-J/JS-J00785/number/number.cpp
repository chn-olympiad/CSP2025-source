#include <bits/stdc++.h>
using namespace std;
int a[1000005];
int main()
{
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> s;
    int l = s.size();
    int cnt = 1;
    for(int i = 0; i < l; i++)
    {
        if(isdigit(s[i])) a[cnt] = s[i] - '0', cnt++;
    }
    sort(a + 1, a + cnt + 1);
    for(int i = cnt; i > 1; i--)
        cout << a[i];
    return 0;
}
