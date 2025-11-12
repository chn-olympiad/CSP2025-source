#include<bits/stdc++.h>
using namespace std;
char  a[10000005];
bool cmp(int x, int y)
{
    return x > y;
}
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin >> s;
    string t;
    int n = s.size();
    for (int i = 0;i < n;i++)
    {
        if(s[i]>= '0'&&s[i] <='9')
            t += s[i];

    }
    int m = t.size();
    for (int i = 0;i <m;i++)
    {
        a[i] = int (t[i]);
    }
    sort (a,a+n,cmp);
    for (int i = 0;i < n;i++)
    {
        cout << a[i];
    }
    return 0;
}
