#include<bits/stdc++.h>
using namespace std;
long long n,k,a[500005],b[500005],ans;
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(long long i=1;i<=n;i++)
    {
        cin>>a[i];
        b[i]=b[i-1]^a[i];
    }
    long long o=1;
    for(long long i=1;i<=n;i++)
    {
        for(long long j=i;j>=o;j--)
        {
            if((b[i]^b[j-1])==k)
            {
                o=i+1;
                ans++;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
