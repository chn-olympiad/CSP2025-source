#include <bits/stdc++.h>
using namespace std;

string s;
char a[1000005];

bool cmp(char a, char b)
{
    return a>b;
}

int main()
{
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    cin >> s;
    int sum = 0, n = s.size();
    for(int i=0; i<=n+1; i++)
    {
        if(s[i]>='0'&&s[i]<='9')
        {
            a[i] = s[i];
            sum++;
        }
    }
    sort(a, a+n+1, cmp);
    for(int i=0; i<=sum; i++)
    {
        cout << a[i];
    }
    return 0;
}
