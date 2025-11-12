#include<bits/stdc++.h>
#define int long long
using namespace std;
#define int long long
const long long mod=998244353;
int n,a[5010],num[100100],k,ans;
bool ch;
signed main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]!=1)ch=true;
    }
    if(!ch)
    {
        int ans=1;
        for(int i=1;i<=n;i++)
        {
            ans*=2;
            ans%=mod;
        }
        cout<<ans-n-n*(n-1)/2-1;
        return 0;
    }
    sort(a+1,a+n+1);
    num[0]=1;
    for(int i=1;i<=n;i++)
    {
        k=0;
        for(int j=50000;j>=0;j--)
        {
            num[a[i]+j]+=num[j];
            num[a[i]+j]%=mod;
            if(a[i]+j>2*a[i])k+=num[j];
            k%=mod;
        }
        ans+=k;
        ans%=mod;
    }
    cout<<ans;
    return 0;
}
