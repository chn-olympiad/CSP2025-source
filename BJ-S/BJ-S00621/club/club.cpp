#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int a[100005][4];
int maxn(n)
{
    freopen("club.in","r",stdin);
    freopen("club.out,"w",stdout);
   int m=0,w[100005],x,v[100005][4],nm[4],sum=0,y=1e8,l[100005]=(),h[10005];
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=3;j++)
        {
            if(a[i][j]>=m)
            {
                m=a[i][j];
                x=j;

            }

        }
        w[n]=m;
        nm[x]++;
        h[i]=j;
    }
    for(int i=1;i<=n;i++)
    {
        sum+=w[i];
    }
    if(nm[1]<=n/2&&nm[2]<=n/2&&nm[3]<=n/2)
    {
        return sum;
    }
  /*int a=nm[1]-n/2,b=nm[2]-n/2,c=nm[3]-n/2,d[4][100005];
    if(a>0) d[1]=1;
    if(b>0) d[2]=2;
    if(c>0) d[3]=3;
    for(int k=1;k<=3;k++)
    {


    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=3;j++)
        {
            if(a[i][j]!=w[i]&&j==d[k])
            {

                    if(h[i]==d[k])
                    {
                        if(a[i][j]<y)l[i]=a[i][j];
                    }
            }
        }
    }
    sort(l+1,l+n);
    for(int i=1;i<=
    }*/
}
int main()
{
    int t,n;
    cin>>t;
    for(int i=1; i<=t; i++)
    {
        cin>>n;
        for(int j=1; j<=n; j++)
        {
            for(int k=1;k<=3;k++)
            {
                cin>>a[j][k];
                cout<<maxn(n);
            }
        }
    }
    return 0;
}
