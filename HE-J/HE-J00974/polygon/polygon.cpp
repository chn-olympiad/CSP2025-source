#include <bits/stdc++.h>
using namespace std;
int c(int n,int m,int sum3)
{
    int sum1=1,sum2=1;
    for (int i=2;i<=m;i++)
    {
        sum2*=i;
    }
    for (int i=2;i<=n-m;i++)
    {
        sum1*=i;
    }
    return sum3/(sum2*sum1);
}
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int a,b[5005];
    cin>>a;
    if (a=3)
    {
        cin>>b[1]>>b[2]>>b[3];
        if (b[1]+b[2]>b[3] && b[1]+b[3]>b[2] && b[2]+b[3]>b[1])
        {
            cout<<1;
            return 0;
        }
        else
        {
            cout<<0;
            return 0;
        }
    }
    int sum=0,sum1=1;
    for (int i=2;i<=a;i++)
    {
        sum1*=i;
    }
    for (int i=4;i<=a;i++)
    {
        sum+=c(a,i,sum1);
    }
    for (int i=1;i<=n;i++)
    {
        cin>>b[i];
    }
    for (int i=1;i<=a-2;i++)
    {
        for (int j=i+1;j<=a-1;j++)
        {
            for (int k=j+1;k<=a;k++)
            {
                if (b[1]+b[2]>b[3] && b[1]+b[3]>b[2] && b[2]+b[3]>b[1])
                {
                    sum++;
                }
            }
        }
    }
    cout<<sum;
    return 0;
}
