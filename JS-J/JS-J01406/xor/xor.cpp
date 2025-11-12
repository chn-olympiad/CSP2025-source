#include <bits/stdc++.h>
using namespace std;
long long n,k,d,f1=LONG_MAX,f2=0;
long long a[500005];
long long kf(long long l,long long r)
{
    long long k=0;
    while (l<=r)
    {
        k=(k^a[l]);
        l++;
    }
    return k;
}
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    long long i,q,z;
    cin>>n>>k;
    for (i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for (i=0;i<n;i++)
    {
        for (q=1;q<=n-i;q++)
        {
            if (a[q+i]<0)
            {
                q=-a[q+i];
            }
            if (kf(q,q+i)==k)
            {
                d++;
                for (z=q;z<=q+i;z++)a[z]=-q-i-1;
            }
        }
    }
    cout<<d;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
