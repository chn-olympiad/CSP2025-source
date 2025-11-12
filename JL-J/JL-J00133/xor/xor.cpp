#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll a[500010],k,n,ans;
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(a[i]==k)
            {
                ans++;
                i++;
            }
            if(j<i) continue;
            int u=a[i];
            for(int e=i+1;e<=j;e++)
            {
                u^=a[e];
            }
            if(u==k)
            {
                ans++;
                i=j+1;
                j++;
            }
        }
    }
    cout<<ans;
    return 0;
}
