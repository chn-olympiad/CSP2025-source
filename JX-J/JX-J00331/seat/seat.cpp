#include <bits/stdc++.h>
using namespace std;
int n,m,a[100001],k;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    scanf("%d%d%d",&n,&m,&a[1]);
    k=a[1];
    for(int i=2;i<=n*m;i++)
    {
        scanf("%d",&a[i]);
    }
    sort(a+1,a+n*m+1);
    int x=lower_bound(a+1,a+n+1,k)-a;
    x=n*m-x+1;
    int l=x%m,r=x/m;
    if(l!=0)
    {
        r++;
        if(r%2==0)
        {
            printf("%d %d\n",r,n-l+1);
        }
        else
        {
            printf("%d %d\n",r,l);
        }
    }
    else
    {
        if(r%2==0)
        {
            printf("%d %d\n",r,1);
        }
        else
        {
            printf("%d %d\n",r,m);
        }
    }
    return 0;
}
