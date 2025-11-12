#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string a="";
    long long b[20];
    b[0]=0;
    b[1]=0;
    b[2]=0;
    b[3]=0;
    b[4]=0;
    b[5]=0;
    b[6]=0;
    b[7]=0;
    b[8]=0;
    b[9]=0;
    getline(cin,a);
    for(int i=0;i<=a.size();i++)
    {
        if (a[i]=='0')
        {
            b[0]++;
        }
        if (a[i]=='1')
        {
            b[1]++;
        }
        if (a[i]=='2')
        {
            b[2]++;
        }
        if (a[i]=='3')
        {
            b[3]++;
        }
        if (a[i]=='4')
        {
            b[4]++;
        }
        if (a[i]=='5')
        {
            b[5]++;
        }
        if (a[i]=='6')
        {
            b[6]++;
        }
        if (a[i]=='7')
        {
            b[7]++;
        }
        if (a[i]=='8')
        {
            b[8]++;
        }
        if (a[i]=='9')
        {
            b[9]++;
        }
    }
    for(int i=1;i<=b[9];i++)
    {
        cout<<"9";
    }
    for(int i=1;i<=b[8];i++)
    {
        cout<<"8";
    }
    for(int i=1;i<=b[8];i++)
    {
        cout<<"8";
    }
    for(int i=1;i<=b[7];i++)
    {
        cout<<"7";
    }
    for(int i=1;i<=b[6];i++)
    {
        cout<<"6";
    }
    for(int i=1;i<=b[5];i++)
    {
        cout<<"5";
    }
    for(int i=1;i<=b[4];i++)
    {
        cout<<"4";
    }
    for(int i=1;i<=b[3];i++)
    {
        cout<<"3";
    }
    for(int i=1;i<=b[2];i++)
    {
        cout<<"2";
    }
    for(int i=1;i<=b[1];i++)
    {
        cout<<"1";
    }
    for(int i=1;i<=b[0];i++)
    {
        cout<<"0";
    }
    return 0;
}
