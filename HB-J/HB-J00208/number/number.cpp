#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000005],n=1;
bool x(int g1,int g2)
    {
        return g1>g2;
    }
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<=s.length();i++)
    {
        if('0'<=s[i] and s[i]<='9')
        {
            a[n]=s[i]-'0';
            n++;
        }
    }
    n--;
    sort(a+1,a+n+1,x);
    for(int i=1;i<=n;i++)
    {
        cout<<a[i];
    }
    return 0;
}
