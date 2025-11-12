#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int n,m,a[105],g,p;
bool cmp(int x,int y)
{
    return x>y;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n*m;i++)
    {
        scanf("%d",&a[i]);
        if(i==1)
        {
            g=a[i];
        }
    }
    sort(a+1,a+n*m+1,cmp);
    for(int i=1;i<=n*m;i++)
    {
        if(a[i]==g)
        {
            p=i;
        }
    }
    if(n==1)
    {
        printf("%d %d",p,1);
    }
    else
    {
        int c=(p+n-1)/n,r=0;
        if(c%2==0)
        {
            if(p%n==0)
            {
                r=1;
            }
            else
            {
                r=n-p%n+1;
            }
        }
        else
        {
            if(p%n==0)
            {
                r=n;
            }
            else
            {
                r=p%n;
            }
        }
        printf("%d %d",c,r);
    }
    return 0;
}
