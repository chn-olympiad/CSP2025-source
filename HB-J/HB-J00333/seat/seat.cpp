#include <iostream>
#include <algorithm>
using namespace std;
const int N=100001;

int m,n;
struct SZ
{
    int a;
    int b;
}s[N];
bool cmp(SZ x,SZ y)
{
    if(x.a>y.a)return 1;
    return 0;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int v;

    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            scanf("%d",&v);
            s[(i-1)*m+j].a=v;
        }
    }
    s[1].b=1;
    int p=0;
    sort(s+1,s+1+n*m,cmp);
    for(int i=1;i<=n*m;i++)
    {
        if(s[i].b)
        {
            p=(i-1)/n+1;
            i-=(p-1)*n;
            printf("%d ",p);
            if(p%2==1)
            {
                printf("%d",i);
            }
            else{
                printf("%d",n-i+1);
            }
            
            return 0;
        }
    }
    return 0;
}