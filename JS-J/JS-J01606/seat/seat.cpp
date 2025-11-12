#include <bits/stdc++.h>
using namespace std;
int n,m,sum=1,ming;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    scanf("%d%d",&n,&m);
    scanf("%d",&ming);
    for(int i=2;i<=n*m;++i)
    {
        int a;
        scanf("%d",&a);
        if(a>ming) sum++;
    }
    int x,y;
    if(sum%n!=0)
    {
        x=sum/n+1;
        sum=sum%n;
        if(x%2!=0) y=sum;
        else y=n-sum+1;
    }
    else
    {
        x=sum/n;
        if(x%2!=0) y=n;
        else y=1;
    }
    printf("%d %d",x,y);
    return 0;
}
