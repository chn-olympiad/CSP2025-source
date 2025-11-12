#include <bits/stdc++.h>
using namespace std;
int n,a[5001],m=3,sum,ans,b[5001][5001],x,c[5001],t=1,f,z;
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        c[a[i]]++;
        z=max(z,a[i]);
    }
    sort(a+1,a+1+n);
    for(int i=1;i<=z;i++)
    {
        if(c[i]!=0&&c[i]!=1)
            t*=(c[i]-1);
            if(c[i]>=2)
                f++;
    }
    if(f>0)
    ans+=t;
    do
    {
        m=3;
        while(m<=n)
        {
            for(int i=1;i<=m;i++)
            {
                sum+=a[i];
                x=max(x,a[i]);
                c[i]=a[i];
            }
            if(sum>x*2&&b[m][sum]==0)
            {
                ans++,b[m][sum]++;
            }
            m++;
            sum=0;
            x=0;
        }
    }
    while(next_permutation(a+1,a+1+n));
    cout<<ans;
    return 0;
}
