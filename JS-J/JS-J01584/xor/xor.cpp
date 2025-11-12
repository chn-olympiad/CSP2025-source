#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+10;
ll n,k;
ll a[N];
ll sum[N];
ll last[N];
ll pos,ans;
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>n>>k;
    for(int i=1; i<=n; ++i)
    {
        cin>>a[i];
        sum[i]=sum[i-1]^a[i];
        for(int j=i-1; j>=0; --j)
        {
            if((sum[i]^sum[j])==k)
            {
                last[i]=j+1;
                break;
            }
        }
    }
    for(int i=1; i<=n; ++i)
    {
        if(last[i]>pos)
        {
            pos=i;
            ans++;
        }
    }
    cout<<ans;
    return 0;
}
