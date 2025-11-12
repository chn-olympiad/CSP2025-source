#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin >> s;
    int n = s.length(),a[15];
    memset(a,0,sizeof(a));
    for(int i = 0;i<n;i++)
    {
        if(s[i]>='0'&&s[i]<='9')
        {
            a[s[i]-'0']++;
        }
    }
    bool ok=0;
    for(int i = 9;i>=1;i--)
    {
        for(int j = 1;j<=a[i];j++)
        {
            cout << i;
            ok = 1;
        }
    }
    if(ok)
    {
        for(int i = 1;i<=a[0];i++)
        {
            cout << 0;
        }
    }
    else
    {
        cout << 0;
    }
    return 0;
}
