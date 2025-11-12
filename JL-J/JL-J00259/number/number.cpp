#include <bits/stdc++.h>
using namespace std;
string s;
int t[1000010];
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    int n=s.length();
    int m=0;
    for(int i=0; i<n; i++)
    {
        if (s[i]>='0' && s[i]<='9')
        {
            t[m]=s[i]-'0';
            m++;
        }
    }
    sort(t,t+m);
    for (int i=m-1; i>=0; i--)
    {
        if (i==m-1)
        {
            cout<<t[i];
        }
        else  if (t[i]!=0)
        {
            cout<<t[i];
        }
        else if (t[m-1]!=0)
        {
            cout<<t[i];
        }
    }
    return 0;
}
