#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int sum[N],dp[N],a[N];
void solve()
{
    int n,k,ans=0;
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]==1)ans++;
    }
    if(k==0)
    {
        cout<<ans/2;
    }else if(k==1){
        cout<<ans;
    }else{
        ans=0;
        for(int i=1;i<=n;i++)
        {
            if(a[i]==k)ans++;
        }
        cout<<ans;
    }
}
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int T=1;
    while(T--)
    {
        solve();
    }
    return 0;
}
