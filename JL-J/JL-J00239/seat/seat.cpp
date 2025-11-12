#include<bits/stdc++.h>
using namespace std;
int a[1100];
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,x,y,z,i;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n*m;i++)
    {
        scanf("%d",&a[i]);
    }
    x=a[1];
    sort(a+1,a+n*m+1);
    for(i=1;i<=n*m;i++)
    {
        if(a[i]==x)
        {
            y=n*m-i+1;
            break;
        }
    }
    z=(y-1)/n;
    y%=n;
    if(y==0)y=n;
    printf("%d ",z+1);
    if((z%2)==0)printf("%d",y);
    else printf("%d",n+1-y);
    return 0;
}
