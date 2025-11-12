#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
using namespace std;
ll n,k;
ll a[500010];
ll ans=0;
bool flag=1;
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]!=1)
        {
            flag=0;
        }
    }
    if(flag)
    {
        if(k==1)
        {
            cout<<n;
        }
        else
        {
            cout<<n/2;
        }
        return 0;
    }
    if(k==1)
    {
        for(int i=1;i<=n;i++)
        {
            if(a[i])
            {
                ans++;
            }
        }
        cout<<ans;
        return 0;
    }
    else
    {
        for(int i=1;i<=n;i++)
        {
            if(!a[i])
            {
                ans++;
            }
            else
            {
                if(a[i]&a[i+1])
                {
                    ans++;
                    i++;
                }
            }
        }
        cout<<ans;
    }
    return 0;
}
