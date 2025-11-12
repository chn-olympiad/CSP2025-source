#include<bits/stdc++.h>
using namespace std;
int a[200005];
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n,k;
    int ans1=0,ans0=0;
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]==1) ans1++;
        if(a[i]==0) ans0++;
    }
    if(ans1==n&&k==0)
    {
        cout<<0<<'\n';
    }
    else if(ans1+ans0==n)
    {
        if(k==0) cout<<ans0<<'\n';
        else cout<<ans1<<'\n';
    }
    else if(k==0)
    {
        cout<<ans0<<'\n';
    }
    else 
    {
        int ans=0,ansj=0;
        for(int i=1;i<=n;i++)
        {
            if(a[i]==k)
            {
                ans++;
                a[i]=-1;
            } 
            else if(a[i]%2==1) ansj++;
        }
        cout<<ans+ansj/2;
    }
    return 0;
}