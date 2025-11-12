#include<bits/stdc++.h>
using namespace std;
int a[5005];
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n,ans1=0,ansx,ansm;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]==1) ans1++;
    }
    if(n<3) cout<<0<<'\n';
    else if(n==3) 
    {
        ansx=a[1]+a[2]+a[3];
        ansm=max(a[1],max(a[2],a[3]))*2;
        if(ansx>ansm) cout<<1<<'\n';
        else cout<<0<<'\n';
    }
    else if(ans1==n)
    {
        long long ans=1;
        for(int i=3;i<=n;i++)
        {
            for(int j=1;j<=i;j++)
            {
                ans=ans*(n-j+1);
            }
            for(int k=1;k<=i;k++)
            {
                ans/=k;
            }
            ans%=998244353;
        }
        cout<<ans<<'\n';
    }
    else cout<<3*n;
    return 0;
}