#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int t,n,a[11][3],ma1[100],m,p,b[11][3],g,z,sum,pp,ans[11];
bool cmp(int a,int b)
{
    return a<b;
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);

    cin>>t;
    for(int l=0;l<t;l++)
    {
        cin>>n;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<3;j++)
            {
                cin>>a[i][j];
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<3;j++)
            {
                if(a[i][j]>m)
                {
                    m=a[i][j];
                    p=j;
                }
            }
            ma1[i]=m;
            m=0;
            b[i][p]=1;
            p=0;
        }
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<n;j++)
            {
                g=b[j][i]+g;

            }
            if(g>0.5*n)
            {
                z++;

            }
            g=0;
        }
        if(z>0)
        {
             if(z>1)
             {for(int c=0;c<n;c++)
                {
                    sum=sum+ma1[c];
                }
                cout<<sum-1<<endl;
                continue;
             }
             else
             {
                 for(int c=0;c<n;c++)
                {
                    sum=sum+ma1[c];
                }
                cout<<sum-2<<endl;
                continue;
             }
            sum=0;
            pp=0;
            continue;
        }
        else
        {
            for(int c=0;c<n;c++)
                {
                    sum=sum+ma1[c];
                }

                cout<<sum<<endl;
                continue;
        }

    }
    return 0;
}
