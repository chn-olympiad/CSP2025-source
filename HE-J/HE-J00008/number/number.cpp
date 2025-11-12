#include <bits/stdc++.h>
using namespace std;
string s;
char a[1000000];
int t;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0; s[i]!='\0'; i++)
    {
        if(s[i]>=0 and s[i]<=9)
        {
            a[i]=s[i];
        }

    }
    for(int i=0; a[i]!='\0'; i++)
    {
        t=i;
    }
    sort(a+t,a);
    for(int i=0; i<t; i++)
    {
        cout<<a[i];
    }
    return 0;
}

