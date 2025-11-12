#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+10;
int n,k,ans,idx;
int a[N],v[N];
int h[N];
signed main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin>>n>>k;
    bool flag1=0,flag2=0;
    for(int i=1;i<=n;i++) 
    {
        cin>>a[i];
        if(a[i]!=1) flag1=1;
        if(a[i]>1) flag2=1;
    }
    if(!flag1)
    {
        if(k!=0&&k!=1)
        {
            cout<<0;
            return 0;
        }
        for(int i=1;i<=n;i++)
        {
            if(a[i]==k&&k==1) ans++;
        }
        if(k==1) cout<<ans<<'\n';
        else cout<<n/2<<'\n';
        return 0;
    }
    else if(!flag2)
    {
        if(k==1)
        {
            for(int i=1;i<=n;i++)
            {
                if(a[i]==k) ans++;
            }   
            cout<<ans<<'\n';
            return 0;
        }
        else if(k==0)
        {
            int sum=0;
            for(int i=1;i<=n;i++)
            {
                if(a[i]==1) sum++;
                if(a[i]==k) ans++;
            }
            cout<<ans+sum/2<<'\n';
            return 0;
        }
        else cout<<0<<'\n';
        return 0;
    }
    for(int l=1;l<=n;l++)
    {
        int sum=0,r;
        int flag=0;
        for(r=l;r<=n;r++)
        {
            if(h[a[r]])
            {
                flag=-1;
                break;
            }
            sum^=a[r];
            h[a[r]]=1;
            if(sum==k)
            {
                flag=1;
                ans++;
                break;
            }
        }
        if(flag==1) continue;
        for(int i=l;i<=r;i++) h[i]=0;
    }
    cout<<ans<<'\n';
    return 0;
}
/*
4 0
2 1 0 3

4 3
2 1 0 3

4 2
2 1 0 3
*/