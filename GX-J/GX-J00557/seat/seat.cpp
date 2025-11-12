#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll n,m;
ll a[10001];
ll rate=1;
ll c,r;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
    scanf("%lld %lld",&n,&m);
    for(ll i=1; i<=n*m; i++)
        scanf("%lld",a+i);
    for(int i=1; i<=n*m; i++)
        if(a[i]>a[1])
            rate++;
    c=rate/n+(rate%n!=0);
    rate%=n;
    if(rate==0) rate=n;
    if(c%2==1)
    {
        r=rate;
    }
    else
    {
        r=n-rate+1;
    }
    printf("%lld %lld",c,r);
    return 0;
}

