#include <bits/stdc++.h>
using namespace std;
long long n,m,a[500005],sum=0;
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>m;
    for(long long i=1;i<=n;i++) cin>>a[i];
    for(long long i=1;i<=n;i++)
    {
        for(long long j=n;j>=i;j--)
        {
            if(i==j&&a[i]==m) sum++;
        }
    }
    cout<<sum;
    return 0;
}
