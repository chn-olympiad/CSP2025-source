#include<bits/stdc++.h>
using namespace std;
long long int n,m,c,c1,c2,c3=0;
double a[10000005];
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    for(long long int i=0;i<n*m;i++)scanf("%lld",&a[i]);
    c=a[0];
    sort(a,a+n*m);
    for(long long int i=n*m-1;i>=0;i--)
    {
        c3++;
        if(c==a[i])break;
    }
    if(c3%n!=0)c1=((c3+(n-(c3%n)))/n);
    else c1=(c3/n);

    if(c1%2!=0)
    {
       if(c3>n)c2=(c3%n);
       else c2=c3;
    }
    else c2=((n+1)-(c3/2));
    printf("%lld",c1);
    cout<<" ";
    printf("%lld",c2);
    return 0;
}
