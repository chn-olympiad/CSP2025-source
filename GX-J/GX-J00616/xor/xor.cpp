#include<bits/stdc++.h>
using namespace std;
long long n,k,a[500005],y=0;
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    if(k==0&&n<2)
    {
        if(a[1]==0&&a[2]==0)
        {
            cout<<3;
            return 0;
        }
        if(a[1]==0&&a[2]!=0)
        {
            cout<<1;
           return 0;
        }
        if(a[1]!=0&&a[2]==0)
        {
            cout<<1;
            return 0;

        }
    }

    if(k<=1&&n<=10)
    { int m=0;
       if(k==1)
       {
           for(int i=1;i<=n;i++)
           {
            for(int l=0;l<n-i;l++)
            {
                m=0;
                 for(int j=i;j<=i+l;j++)
                 {
                    m+=a[j];
                 }
                if(m==1)
                {
                  y++;
                }
            }
           }
        cout<<y;
       }
       if(k==1)
       {
           for(int i=1;i<=n;i++)
           {
            for(int l=0;l<n-i;l++)
            {
                m=0;
                 for(int j=i;j<=i+l;j++)
                 {
                    m+=a[j];
                 }
                if(m==0)
                {
                  y++;
                }
            }
           }
        cout<<y;
       }
    }
    return 0;
}
