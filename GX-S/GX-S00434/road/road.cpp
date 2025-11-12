#include <bits/stdc++.h>
using namespace std;

long long t,n,a[200000],b[200000],c[200000],ma=0,z[1000000],q=0,sum=0;
int main()
{
    //freopen("club.in","r",stdin);
    //freopen("club.out","w",stdout);
    cin>>t;
    for(int i=0; i<t; i++)
    {
        cin>>n;
        ma=n/2;
        for(int j=0; j<n; j++)
        {
            scanf("%lld %lld %lld",&a[j],&b[j],&c[j]);
        }
        sort(a,a+n);
        for(int j=n; j>ma; j--)
        {
            sum+=a[j];
        }
    }
}
