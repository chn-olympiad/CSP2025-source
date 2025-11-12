#include<bits/stdc++.h>
using namespace std;
/*int RP;
RP++;*/
int big(int a,int b)
{
    return a>b;
}
string s;
char a[1000000]={};
int main()
{
    freopen("number.in",r,stdin);
    freopen("number.out",w,stdout);
    cin>>s;
    for(int i=0;i<sizeof(s);i++)
    {
        if(s[i]!='0' and s[i]!='1' and s[i]!='2' and s[i]!='3' and s[i]!='4' and s[i]!='5' and s[i]!='6' and s[i]!='7' and s[i]!='8' and s[i]!='9')
        {
            s[i]=' ';
        }
    }
    for(int i=0;i<sizeof(s);i++)
    {
        if(s[i]==' ')
        {
            s[i]=s[i+1];
            s[i+1]=' ';
        }
    }
    for(int i=0;i<sizeof(s);i++)
    {
        a[i]=char(s[i]);
    }
    sort(a,a+sizeof(s),big);
    for(int i=0;i<sizeof(s);i++)
    {
        if(a[i]==' ') continue;
        cout<<a[i];
        i++;
    }
    return 0;
}
