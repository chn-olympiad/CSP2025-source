#include <bits/stdc++.h>
using namespace std;
int m,x,flag,t,g,minn=99999999999,f;
string n;
int s[1100005],c[1000005],d;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n.length();i++)
    {
        if(!isdigit(n[i]))
        {
            n[i]='f';
        }
        else{
            s[i]=n[i];
        }

    }
    for(int i=1;i<=n.length();i++)
    {
        if(s[i]<=s[i-1])
        {
            t=0;
            t=s[i-1];
            s[i-1]=s[i];
            s[i]=t;
        }
    }
    for(int i=n.length();i>=1;i--)
    {

        if(s[i]!=0)
        {
            cout<<s[i];
        }
    }
    return 0;
}
