#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen(number.in,'r',stdin)
    freopen(number.out,'w',stdout)
    string s;
    int a[1000000];
    int e=0;
    cin>>s;
    for(int i=0;i<1000000;i++)
    {
        if(s[i]=='0')
        {
            a[e]=0;
            e++;
        }
        if(s[i]=='1')
        {
            a[e]=1;
            e++;
        }
        if(s[i]=='2')
        {
            a[e]=2;
            e++;
        }
        if(s[i]=='3')
        {
            a[e]=3;
            e++;
        }
        if(s[i]=='4')
        {
            a[e]=4;
            e++;
        }
        if(s[i]=='5')
        {
            a[e]=5;
            e++;
        }
        if(s[i]=='6')
        {
            a[e]=6;
            e++;
        }
        if(s[i]=='7')
        {
            a[e]=7;
            e++;
        }
        if(s[i]=='8')
        {
            a[e]=8;
            e++;
        }
        if(s[i]=='9')
        {
            a[e]=9;
            e++;
        }
    }

    for(int i=0;i<e;i++)
    {
        for(int j=1;j<e;j++)
        {
            if(a[i]<a[j])
            {
                int d=a[i];
                a[i]=a[j];
                a[j]=d;
            }
        }
    }

    for(int i=0;i<e;i++)
        cout<<a[i];






    return 0;
}
