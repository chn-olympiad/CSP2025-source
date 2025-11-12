#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int M=5e3+10;
const ll mod=998244353;
ll n,ans,a[M];
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<n-1;i++)
    {
        ans+=1ll*i*(i+1)/2;
    }
    cout<<ans;
    return 0;
}
