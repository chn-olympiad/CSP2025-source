#include <bits/stdc++.h>
using namespace std;
int a[1000007],k;
string s;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin >> s;
    int l = s.length();
    for (int i = 0;i < l;i++)
    {
        if ('0'<=s[i]&&'9'>=s[i])
        {
            a[k]=s[i]-'0';
            k++;
        }
    }
    sort(a,a+k);
    for (int i = k-1;i >= 0;i--)
    {
        cout << a[i];
    }
}
