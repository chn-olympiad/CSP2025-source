#include<bits/stdc++.h>
using namespace std;

bool cmp(int a, int b)
{
    return a > b;
}

int a[1000005];

int main()
{
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    string s;
    int cnt = 0;
    cin >> s;
    for(int i=0; i<s.size(); i++)
    {
        if(isdigit(s[i]) == 1)
        {
            cnt++;
            a[cnt] = s[i] - '0';
        }
    }
    sort(a, a+cnt, cmp);
    for(int i=0; i<cnt; i++)
    {
        cout << a[i];
    }
    return 0;
}
