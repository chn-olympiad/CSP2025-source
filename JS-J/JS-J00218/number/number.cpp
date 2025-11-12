#include<bits/stdc++.h>
using namespace std;
char a[1000000];
int b[1000000];
int main()
{
    //freopen("number.in","r",stdin);
    //freopen("number.out","w",stdout);
    string s;
    long long d=0,e=0;
    cin>>s;
    int c=0;
    for(int i=0;i<s.size();i++)
    {
        a[i]=s[i];
    }
    for(int i=0;i<s.size();i++)
    {
        if(a[i]=='0')
        {
            b[i]=0;
            e++;
        }
        if(a[i]=='1')
        {
            b[i]=1;
            e++;
        }
        if(a[i]=='2')
        {
            b[i]=2;
            e++;
        }
        if(a[i]=='3')
        {
            b[i]=3;
            e++;
        }
        if(a[i]=='4')
        {
            b[i]=4;
            e++;
        }
        if(a[i]=='5')
        {
            b[i]=5;
            e++;
        }
        if(a[i]=='6')
        {
            b[i]=6;
            e++;
        }
        if(a[i]=='7')
        {
            b[i]=7;
            e++;
        }
        if(a[i]=='8')
        {
            b[i]=8;
            e++;
        }
        if(a[i]=='9')
        {
            b[i]=9;
            e++;
        }
    }
    for(int i=0;i<s.size();i++)
    {
        for(int j=0;j<s.size();j++)
        {
            if(b[i]>b[j])
            {
                c=b[i];
                b[i]=b[j];
                b[j]=c;
            }
        }
    }
    for(int i=0;i<e;i++)
    {
        d=b[i]+d*10;
    }
    cout<<d;
    return 0;
}
