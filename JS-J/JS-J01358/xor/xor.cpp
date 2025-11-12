#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,k,a[500010],ans;
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n;i++)
    {
        if(a[i]==k)
        {
            ans++;
            continue;
        }
        for(int j=i+1;j<=n;j++)
        {
            if(a[i]+a[j]==k || abs(a[i]-a[j])==k)
            {
                ans++;
                i=j+1;
                break;
            }
        }
    }
    cout<<ans;
    return 0;
}
