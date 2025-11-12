#include <bits/stdc++.h>

using namespace std;

int n,a[5005];

const int R=998244353;

long long f[5005][5005];

int c(int p,int q)
{
    int t=1;
    for(int i=1;i<=p;i++)
    {
        t=(t*q)%R;
        q--;
    }
    for(int i=1;i<=p;i++)
    {
        t/=i;
    }
    t%=R;
    return (int)t;
}

int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",a+i);
    }
    sort(a+1,a+n+1);
    if(n==3)
    {
        if(a[1]+a[2]>a[3])
            printf("1");
        else
            printf("0");
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=i;j++)
        {
            f[i][0]+=c(j,i);
            f[i][0]%=R;
        }

    }
    for(int i=1;i<=5000;i++)
    {
        f[1][i]=(a[1]>i);
    }
    for(int i=1;i<=5000;i++)
    {
        for(int j=1;j<=5000;j++)
        {
            if(j<a[i])f[i][j]=f[i-1][0]+1+f[i-1][j];
            else f[i][j]=f[i-1][j]+f[i-1][j-a[i]];
            f[i][j]%=R;
        }
    }
    int tot=0;
    for(int i=1;i<=n;i++)
    {
        tot=(tot+f[i-1][a[i]])%R;
    }
    printf("%d",tot);
}
