#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    int a[9]={0},l=0;
    cin>>s;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='9')
        {
            a[9]++;
        }
        else if(s[i]=='8')
        {
            a[8]++;
        }
        else if(s[i]=='7')
        {
            a[7]++;
        }
        else if(s[i]=='6')
        {
            a[6]++;
        }
        else if(s[i]=='5')
        {
            a[5]++;
        }
        else if(s[i]=='4')
        {
            a[4]++;
        }
        else if(s[i]=='3')
        {
            a[3]++;
        }
        else if(s[i]=='2')
        {
            a[2]++;
        }
        else if(s[i]=='1')
        {
            a[1]++;
        }
        else if(s[i]=='0')
        {
            a[0]++;
        }
    }
    int b=1;
    for(int i=1;i<=a[0];i++)
    {
        b*=10;
    }
    for(int i=1;i<=a[1];i++)
    {
        l+=1*b;
        b*=10;
    }
    for(int i=1;i<=a[2];i++)
    {
        l+=2*b;
        b*=10;
    }for(int i=3;i<=a[3];i++)
    {
        l+=3*b;
        b*=10;
    }for(int i=1;i<=a[4];i++)
    {
        l+=4*b;
        b*=10;
    }for(int i=1;i<=a[5];i++)
    {
        l+=5*b;
        b*=10;
    }for(int i=1;i<=a[6];i++)
    {
        l+=6*b;
        b*=10;
    }for(int i=1;i<=a[7];i++)
    {
        l+=7*b;
        b*=10;
    }for(int i=1;i<=a[8];i++)
    {
        l+=8*b;
        b*=10;
    }for(int i=1;i<=a[9];i++)
    {
        l+=9*b;
        b*=10;
    }
    cout<<l;
    return 0;
}
