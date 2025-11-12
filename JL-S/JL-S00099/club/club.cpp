#include<bits/stdc++.h>
using namespace std;
long long a[100010],b[100010],c[100010];
long long qw[100010];
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    long long t;
    scanf("%lld",&t);
    while(t--)
    {
        long long n;
        long long ans=0;
        scanf("%lld",&n);
        for(int i=1;i<=n;i++)
        {
            scanf("%lld%lld%lld",&a[i],&b[i],&c[i]);
            long long q,w,e;
            q=a[i];
            w=b[i];
            e=c[i];
            qw[1]=q;
            qw[2]=w;
            qw[3]=e;
            sort(qw+1,qw+1+n);
            ans+=qw[3];
        }
        cout<<ans;
    }
    return 0;
}

