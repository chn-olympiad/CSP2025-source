#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    int a[10005],c=0,d=0,e=0,f=0,g=0,h=0,k=0,l=0,m=0,n=0;
    string s;
    cin>>s;
    int b=s.size();
    for(int i=0;i<b;i++)
    {
        a[i]+=s[i];
    }
    for(int i=0;i<b;i++)
    {
        if(a[i]=='9')
        {
            c++;
        }
        else if(a[i]=='8')
        {
            d++;
        }
        else if(a[i]=='7')
        {
            e++;
        }
        else if(a[i]=='6')
        {
            f++;
        }
        else if(a[i]=='5')
        {
            g++;
        }
        else if(a[i]=='4')
        {
            h++;
        }
        else if(a[i]=='3')
        {
            k++;
        }
        else if(a[i]=='2')
        {
            l++;
        }
        else if(a[i]=='1')
        {
            m++;
        }
        else if(a[i]=='0')
        {
            n++;
        }
        else
        {
            continue;
        }
    }
    for(int i=1;i<=c;i++)
    {
        cout<<"9";
    }
    for(int i=1;i<=d;i++)
    {
        cout<<"8";
    }
    for(int i=1;i<=e;i++)
    {
        cout<<"7";
    }
    for(int i=1;i<=f;i++)
    {
        cout<<"6";
    }
    for(int i=1;i<=g;i++)
    {
        cout<<"5";
    }
    for(int i=1;i<=h;i++)
    {
        cout<<"4";
    }
    for(int i=1;i<=k;i++)
    {
        cout<<"3";
    }
    for(int i=1;i<=l;i++)
    {
        cout<<"2";
    }
    for(int i=1;i<=m;i++)
    {
        cout<<"1";
    }
    for(int i=1;i<=n;i++)
    {
        cout<<"0";
    }
    return 0;
}
