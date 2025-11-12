#include<bits/stdc++.h>
using namespace std;
int a[10000001],c[10000001];
int main()
{
    //freopen("number.in","r",stdin);
    //freopen("number.out","w",stdout);
    string s;
    cin>>s;
    int n=0;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='9')
        {
            n++;
            c[i]=9;
        }
        if(s[i]=='8')
        {
            n++;
            c[i]=8;
        }
        if(s[i]=='7')
        {
            n++;
            c[i]=7;
        }
        if(s[i]=='6')
        {
            n++;
            c[i]=6;
        }
        if(s[i]=='5')
        {
            n++;
            c[i]=5;
        }
        if(s[i]=='4')
        {
            n++;
            c[i]=4;
        }
        if(s[i]=='3')
        {
            n++;
            c[i]=3;
        }
        if(s[i]=='2')
        {
            n++;
            c[i]=2;
        }
        if(s[i]=='1')
        {
            n++;
            c[i]=1;
        }
        if(s[i]=='0')
        {
            n++;
            c[i]=0;
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=i;j<n;j++)
        {
            if(c[j]>c[i])
            {
                int k=c[j];
                c[j]=c[i];
                c[i]=k;
            }
        }
        cout<<c[i];
    }
    return 0;
}
