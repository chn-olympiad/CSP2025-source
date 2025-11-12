#include<bits/stdc++.h>
using namespace std;
int t,n,a[200010][4],sum,ans,h[4];
void dfs(int k)
{
    if(k==n+1)
    {
        ans=max(sum,ans);
        return;
    }
    for(int i=1;i<=3;i++)
    {
        if(h[i]<n/2)
        {
            sum+=a[k][i];
            h[i]++;
            dfs(k+1);
            sum-=a[k][i];
            h[i]--;
        }
    }
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--)
    {
        cin>>n;
        h[1]=h[2]=h[3]=0;
        ans=sum=0;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i][1]>>a[i][2]>>a[i][3];
        }
        dfs(1);
        cout<<ans<<endl;
    }
    return 0;
}
