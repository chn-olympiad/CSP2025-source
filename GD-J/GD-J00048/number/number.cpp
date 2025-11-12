//T1 = 100pts
#include <bits/stdc++.h>
using namespace std;
const int N = 1e6+5;
int m = 0;
int a[N];

bool cmp(int x, int y)
{
    return x > y;
}

int main()
{
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    string s;
    cin >> s;
    int len = s.size();
    for(int i = 0; i < len; i++)
    {
        if(s[i] >= '0' && s[i] <= '9')
        {
            a[++m] = s[i] - '0';
        }
    }
    sort(a+1, a+m+1, cmp);
    for(int i = 1; i <= m; i++)
    {
        cout << a[i];
    }
    return 0;
}

//T1 + T2 + T3 + T4 = 100+100+30+36 = 266pts