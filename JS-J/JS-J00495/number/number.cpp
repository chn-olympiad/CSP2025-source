#include <bits/stdc++.h>
using namespace std;
string s;
long long a[15],f;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin >>s;
    for(long long i=0;i<s.size();i++)
    {
        if(s[i]>='0'&&s[i]<='9')
            a[s[i]-'0']++;
    }
    for(int i=1;i<=9;i++)
    {
        if(a[i]!=0)
        {
            f=1;
            break;
        }
    }
    if(f==0)
    {
        cout <<0;
        return 0;
    }

    for(int i=9;i>=0;i--)
    {
        for(long long j=1;j<=a[i];j++)
            cout <<i;
    }
    return 0;
}
