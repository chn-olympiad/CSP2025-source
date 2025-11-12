#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int a[N];
void solve()
{
    int n=0;
    cin>>n;
    if(n==3)
    {
        int x,y,z;
        cin>>x>>y>>z;
        if(max(x,max(y,z))*2<x+y+z)cout<<1;
        else cout<<0;
    }
    else{
        int temp=0;
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
            if(a[i]==1)temp++;
        }
        int ans=0;
        for(int i=3;i<=temp;i++)
        {
            int tp=1;
            for(int j=n;j>=n-i;j--)
                tp*=j;
            int tp1=1;
            for(int j=1;j<=i;j++)
                tp1*=j;
            ans+=tp/tp1;
        }
        cout<<ans<<endl;
    }
}
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int T=1;
    while(T--)
    {
        solve();
    }
    return 0;
}
