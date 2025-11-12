#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,k;
ll a[1009];
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    for(ll i=1;i<=n*m;i++)
        scanf("%lld",&a[i]);
    k=a[1];
    sort(a+1,a+n*m+1);
    for(ll i=n*m;i!=0;i--)
    {
        if(a[i]==k)
        cout<<((n*m-i)/n+1)<<" "<<((((n*m-i)/n+1)%2==1)?((n*m-i)%n+1):(n-(n*m-i)%n));
    }
    return 0;
}
