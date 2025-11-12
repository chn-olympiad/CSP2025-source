#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int a[N];
signed main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,k,ans=0;
    cin>>n>>k;
    for(int i=1; i<=n; ++i)
    {
        cin>>a[i];
        if(a[i]==k)
        {
            ++ans;
        }
    }
    cout<<ans;
    return 0;
}
