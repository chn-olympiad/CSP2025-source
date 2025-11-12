#include<bits/stdc++.h>
using namespace std;
#define int long long
const long long N=2e5+1;
int a[N];
int n,k,ans,num;
signed main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    int f=1;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]==0)
        {
            f=0;
        }
        if(a[i]==1)
        {
            num++;
        }

    }

    if(f==1)
    {
        cout<<n/2;
        return 0;
    }
    if(k==0&&f==0)
    {
        for(int i=1;i<=n;i++)
        {
            if(a[i]==0)
            {
                ans++;

            }
            else if(a[i]==1&&a[i-1]==1)
            {
                ans++;

            }
        }
        cout<<ans;
        return 0;
    }
    if(k==1&&f==0)
    {
        cout<<num;
    }
        return 0;
}
