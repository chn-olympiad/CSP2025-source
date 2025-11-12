#include <bits/stdc++.h>
using namespace std;
int a[1005],b[1005],c[1005];
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int n,m,l,s=0,ss=0;
    cin >>n>>m>>l;
    for(int i=0;i<n;i++)
    {
        cin >>b[i];
        if(l<=1)
        {
            break;
        }
        else
        {
            a[i]=l%10;
            l/=10;
        }
    }
    for(int i=0;i<n;i++)
    {
        if(a[i]==1)
        {
            s++;
        }
    }
    for(int i=1;i<=s;i++)
    {
        for(int j=0;j<n;j++)
        {
            for(int k=j+1;k<n;k++)
            {
                if(b[k]>=i+1)
                {
                    ss+=1;
                }
            }
        }
    }
    for(int i=1;i<n;i++)
    {
        if(b[i]==b[i-1])
        {

            c[i]=1;
            c[i-1]=1;
        }
    }
    int sss=1;
    for(int i=0;i<n;i++)
    {
        if(c[i]==c[i-1])
        {
            sss+=1;
        }
        else
        {
            for(int i=sss;i>=1;i--)
            {
                ss*=sss;
            }
            sss=0;
        }
    }
    cout <<ss%998244353;
    return 0;
}
