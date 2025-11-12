#include <bits/stdc++.h>
using namespace std;

string s;
int a[1000010];
int ans = 0;

bool isDigit(char a)
{
    if(a <= '9' && a >= '0')
        return true;
    return false;
}

int main()
{
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie();cout.tie();

    cin >> s;
    int len = s.size();
    int cnt = 0;
    for(int i = 0; i < len; i++)
    {
        if(isDigit(s[i]))
        {
            a[cnt + 1] = s[i] - '0';
            cnt++;
        }
    }

    sort(a + 1, a + cnt + 1);
    for(int i = cnt; i >= 1; i--)
        cout << a[i];
    return 0;
}
