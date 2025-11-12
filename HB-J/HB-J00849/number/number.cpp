#include <bits/stdc++.h>
using namespace std;
const int N = 1e6+5;

int a[N];
string s;

bool cmp(int a, int b)
{
    return a > b;
}

int main()
{
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);

    cin >> s;
    int len = s.length(), p = 0;
    for(int i = 0; i < len; i ++)
    {
        if(48 <= s[i] && s[i] <= 57) a[++p] = s[i];
    }
    sort(a+1, a+p+1, cmp);
    if(a[1] == '0') cout << 0;
    else for(int i = 1; i <= p; i ++) cout << (char)a[i];

    fclose(stdin);
    fclose(stdout);
    return 0;
}
