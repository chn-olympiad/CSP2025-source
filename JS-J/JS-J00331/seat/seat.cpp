#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[105];
int r;
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
    }
    r=a[1];
    sort(a+1,a+1+n*m,cmp);
    for(int i=1;i<=n*m;i++)
    {
        if(a[i]==r)
        {
            r=i;
            break;
        }
    }
    int nn,mm;
    mm=(r-1)/n+1;
    if(mm%2==0)
    {
        nn=n-(r-1)%n;
    }
    else
    {
        nn=(r-1)%n+1;
    }
    printf("%d %d",mm,nn);
    return 0;
}
