#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,a[5010],ans;
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n-2;i++)
    {
        ans+=i;
    }
    cout<<ans;
    return 0;
}
