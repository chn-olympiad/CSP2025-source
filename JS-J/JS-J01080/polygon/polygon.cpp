#include <bits/stdc++.h>
using namespace std;
int n,a[5005],sum=0;

bool san(int x1,int x2,int x3)
{
    int maxn=x3;
    if(x1+x2>x3)
    {
        return true;
    }
    return false;

}
int duo(int y1,int y2,int choose)
{
    int con=0,m=1,t=0,d=1;
    int zong[(a[y1]+a[y2])*(y1+y2)/2]={0};
    for(int i=y1;i<=y2;i++)
    {
        for(int j=i+1;j<=y2;j++)
        {
            m++;
        }
    }
    for(int i=1;i<=m;i++)
    {

        for(int j=y1;j<choose;j++)
        {
            zong[i]+=a[d+t];
            t++;
        }
        if(zong[i]>=a[i+t]) con++;
        else
        {
            d++;
            t=1+d;
        }
    }
    return con/2+1;
}
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++)
    {
        for(int j=i;j<=n;j++)
        {
            if(a[i]>=a[j])
            {
                int t=a[i];
                a[i]=a[j];
                a[j]=t;
            }
        }
    }
    for(int i=3;i<=n;i++)
    {
        if(i==3)
        {
            for(int j=1;j<=n-2;j++)
            {
                for(int k=j+1;k<=n-1;k++)
                {
                    for(int l=k+1;l<=n;l++)
                    {
                        if(san(a[j],a[k],a[l])==true)
                        {
                            sum++;
                        }
                        else
                        {
                            break;
                        }
                    }
                }
            }
        }
        else
        {
            for(int j=1;j<=n-i;j++)
            {
                sum+=duo(j,n,i);
            }
        }
    }
    cout<<sum;
    return 0;
}
