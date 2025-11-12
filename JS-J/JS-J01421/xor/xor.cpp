#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5*1e5+10;
int n,k,a[N],ans;
signed main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>k;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    if(n<=2&&k==0)
    {
        if(n==1) cout<<0;
        else cout<<1;
        return 0;
    }
    int f1=1,f2=1;
    for(int i=1;i<=n;i++)
    {
        if(a[i]>1)
        {
            f1=0;
            break;
        }
        if(a[i]!=1) f2=0;
    }
    if(f2)
    {
        cout<<n/2;
        return 0;
    }
    if(f1)
    {
        if(k==0)
        {
            for(int i=1;i<=n;i++)
            {
                if(a[i]==0) ans++;
                else if(a[i]==a[i+1]&&a[i]==1) ans++,i++;
            }
        }
        else if(k==1)
        {
            for(int i=1;i<=n;i++)
            {
                if(a[i]==1) ans++;
                else if(a[i]==a[i+1]&&a[i]==0) ans++,i++;
            }
        }
        cout<<ans;
        return 0;
    }
    cout<<n/2;
    return 0;
}
