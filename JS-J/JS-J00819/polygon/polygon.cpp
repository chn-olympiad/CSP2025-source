#include<bits/stdc++.h>
using namespace std;
long long n,a[5005],s[5005];
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(long long i=1;i<=n;i++)
    {
        cin>>a[i];
        s[i]=s[i-1]+a[i];
    }
    long long cnt=0;
    for(long long l=1;l<=n-2;l++)
    {
        for(long long r=l+2;r<=n;r++)
        {
            long long maxn=-1;
            for(long long k=l;k<=r;k++){
                if(a[k]>maxn) maxn=a[k];
            }
            if(2*maxn<s[r]-s[l-1])
            {
                cnt++;
            }
        }
    }
    cout<<cnt%998244353;
    return 0;
}
