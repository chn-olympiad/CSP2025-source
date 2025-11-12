#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a[500005],k,sum1;
signed main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    std::ios::sync_with_stdio(false);
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]==1)sum1++;
    }
    cout<<n/2<<endl;
    return 0;
}
