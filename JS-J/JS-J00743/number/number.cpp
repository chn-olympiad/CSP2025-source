#include <bits/stdc++.h>
using namespace std;
string s;
char c[1000005];
int a[15];
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin >> c;
    for (int i=0;i<1000005;i++)
    {
        if ('0'<=c[i] && c[i]<='9')
        {
            a[c[i]-'0']++;
        }
        if (c[i]==0)
        {
            break;
        }
    }
    for (int i=9;i>=0;i--)
    {
        for (int j=1;j<=a[i];j++)
        {
            cout << i;
        }
    }
    return 0;
}
