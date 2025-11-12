#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353;
int n,a[5001],ans,vis[5001];
inline void dfs(int len,int hea)
{
    if(len==0)
    {
        int sum=0,last=0,res=0;
        for(int i=1;i<n;i++)
        {
            if(vis[i]==true)
            {
                sum+=a[i];
                last=i;
            }
        }
        for(int i=last+1;i<=n;i++)
            if(a[i]<sum)
                res++;
        ans+=res;
        ans%=mod;
        return;
    }
    for(int i=hea+1;i+len-2<n;i++)
    {
        vis[i]=true;
        dfs(len-1,i);
        vis[i]=false;
    }
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+n+1);
    if(n<3)
        cout<<0<<'\n';
    else if(n==3)
    {
        if(a[1]+a[2]<=a[3])
            cout<<0<<'\n';
        else
            cout<<1<<'\n';
    }
    else if(a[1]+a[2]>a[n])
    {
        int c[5001];
        c[3]=n*(n-1)*(n-2)/6;
        ans+=c[3];
        for(int i=3;i<n;i++)
        {
            if(ans>=mod)
                ans%=mod;
            c[i+1]=c[i]*(n-i)/(i+1);
            ans+=c[i+1];
        }
        cout<<ans<<'\n';
    }
    else
    {
        for(int i=2;i<n;i++)
            dfs(i,0);
        cout<<((ans+1)/2)%mod<<'\n';
    }
    return 0;
}
