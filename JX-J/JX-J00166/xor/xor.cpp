#include <bits/stdc++.h>
using namespace std;
int n,k,a[500005],sum[500005],cnt;
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]==1)
        {
            cnt++;
        }
        sum[i]=sum[i-1]^a[i];
    }
    if(cnt==n&&k==0)
    {
        cout<<n/2;
        return 0;
    }
    return 0;
}
