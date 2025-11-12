#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t,n,a[1000],sum[906],z[306],b;
    for(int i=1;i<=905;i++)
    {
        sum[i]=0;
        z[i]=0;
    }
    cin>>t;
    for(int x=1;x<=t;x++)
    {
        cin>>n;
        for(int y=1;y<=n;y++)
        {
                cin>>a[3*y-2]>>a[3*y-1]>>a[3*y];
    for(int i=3*y-2;i<=3*y;i++)
                {
                    for(int j=3*y-i-2;j<=3*y-i;j++)
                    {
                        if(a[j]>a[j+1])
                        {
                            b=a[j];
                            a[j]=a[j+1];
                            a[j+1]=b;
                        }

                    }
                sum[i]+=a[1];
                }
            for(int s=3*y-2;s=3*y;s++)
            {
                z[x]=z[x]+sum[s];
            }
        }
    }
    for(int x=1;x<=t;x++)
    {
        cout<<z[x]<<endl;
    }

    return 0;

}
