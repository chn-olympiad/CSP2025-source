#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,a,b,s=1;
    scanf("%d%d",&n,&m);
    scanf("%d",&a);
    for(int i=1;i<n*m;i++)
    {
        scanf("%d",&b);
        if(b>a) s++;
    }
    int x=(s+n)/n,y=(s+n)%n;
    if(y==0)
    { 
        x--;
        y=n;
    }
    int c,r;
    if(x%2==0)  
    {
         c=x;
         r=n+1-y;
    }
    else
    {
         c=x;
         r=y;
    }
    printf("%d %d",c,r);
    return 0;
}
