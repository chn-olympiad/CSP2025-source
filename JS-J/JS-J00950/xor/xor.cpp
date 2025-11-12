#include<bits/stdc++.h>
#define int long long
using namespace std;
struct qj
{
    int l,r;
}aq[500005];
bool cmp(qj a,qj b)
{
    if(a.l!=b.l)
        return a.l<b.l;
    else return a.r<b.r;
}
int n,k,a[500005],f,f2,dp[105][105],cnt;bool vis[500005];
signed main()
{
    ios::sync_with_stdio(false);
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]!=1)f=1;
        if(a[i]>1)f2=1;
    }
    if(f==0){
        if(k==1)cout<<n<<endl;
        else if(k==0)cout<<n/2<<endl;
        return 0;
    }
    else if(f2==0){
        int ans=0;
        if(k==1){
            for(int i=1;i<=n;i++)
                if(a[i])ans++;
            cout<<ans;
        }
        else if(k==0)
        {
            for(int i=1;i<=n;i++)
                if(a[i]==0)ans++;
                else if(a[i]==1&&i+1<=n&&a[i+1]==1)ans++,i++;
            cout<<ans;
        }
        else if(k>3)cout<<0;
        return 0;
    }
    for(int i=1;i<=n;i++)if(a[i]==k)cnt++,aq[cnt].l=qa[cnt].r=i,vis[i]=1;
    for(int i=1;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            int s=a[i];
            for(int k=i+1;k<=j;k++)
            {
                s=s^a[k];
            }
            if(s==k)cnt++,aq[cnt].l=aq[cnt].r=i;
        }

    }
    sort(aq+1,aq+cnt+1,cmp);
    cout<<ans;
    return 0;
}
