#include<bits/stdc++.h>
using namespace std;
long long n,k;
long long a[500005];
long long ff(long long qs)
{
    for(long long i=qs;i<=n;i++)
    {
        for(long long j=qs;j<=i;j++)
        {
            if((a[i] ^ a[j-1])==k&&j-1>0)
            {
                return ff(i+1)+1;
            }
            if(a[i]==k&&j==1)
            {
                return ff(i+1)+1;
            }
        }
    }
    return 0;
}
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(long long i=1;i<=n;i++)
    {
        cin>>a[i];
        if(i>1)
        {
            a[i]=a[i-1] ^ a[i];
        }
    }
    cout<<ff(1);
    return 0;
}
