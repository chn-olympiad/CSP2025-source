#include<bits/stdc++.h>
using namespace std;
long long n,m,cnt,ii,jj;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ii=1,jj=1;
    scanf("%lld%lld",&n,&m);
    long long x;
    scanf("%lld",&x);
    for(int i=2;i<=n*m;++i)
    {
        long long o;
        scanf("%lld",&o);
        if(o>x)
        {
           if(jj%2==1)
           {
               ii++;
               if(ii>n)
               {
                   ii--;
                   jj++;
               }
           }
           else
           {
               ii--;
               if(ii<1)
               {
                   ii++;
                   jj++;
               }
           }
        }
    }
    printf("%lld %lld",jj,ii);
    return 0;
}
