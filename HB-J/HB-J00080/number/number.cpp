#include <bits/stdc++.h>
using namespace std;
int n,m[1000005];
char a[1000005];
string s;
bool cmp(int x,int y)
{
    return x > y;
}
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin >> s;
    for (int i=0;i <= s.length();i++)
    {
        if (s[i] < 'a')
        {
            a[n] = s[i];
            n++;
        }
    }
    for (int i = 0;i < n-1;i++)
    {
        m[i] = a[i]-48;
    }
    sort (m,m+n+1,cmp);
    for (int i = 0;i < n-1;i++)
    {
        cout << m[i];
    }
    return 0;
}
