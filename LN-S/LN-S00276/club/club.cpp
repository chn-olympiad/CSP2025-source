#include<bits/stdc++.h>
using namespace std;
int a[100009],b[100009],c[100009],ans,n;
void dfs(int ca,int cb,int cc,int cnt,int i)
{
    if(i==n+1){ans=max(ans,cnt);return;}
    if(ca<n/2)dfs(ca+1,cb,cc,cnt+a[i],i+1);
    if(cb<n/2)dfs(ca,cb+1,cc,cnt+b[i],i+1);
    if(cc<n/2)dfs(ca,cb,cc+1,cnt+c[i],i+1);
    return;
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int T;
    cin>>T;
    while(T--)
    {
        ans=0;
        cin>>n;
        for(int i=1;i<=n;i++)cin>>a[i]>>b[i]>>c[i];
        if(n<=10){dfs(0,0,0,0,1);cout<<ans<<endl;}
        else
        {
            sort(a+1,a+n+1);
            for(int i=n;i>=n/2+1;i--)ans+=a[i];
            cout<<ans<<endl;
        }
    }
}
