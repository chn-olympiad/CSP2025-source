#include<bits/stdc++.h>
using namespace std;
int n,a[5001],i,s,j,k,m,ii;
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>a[i];
        for(j=i;j>1;j--)
            if(a[j]>a[j-1])
                swap(a[j],a[j-1]);
    }

    for(i=3;i<=n;i++)
    {
        for(j=1,k=1;j<=n-i;j++,k++)
        {
            m=a[j]+a[j+k];
            for(ii=1;ii<=n-3;ii++)
            {
                if(m+a[j+k+ii]>a[j]*2)s++;
                s%998244353;
            }
        }
    }
    cout<<s;
    return 0;
}
