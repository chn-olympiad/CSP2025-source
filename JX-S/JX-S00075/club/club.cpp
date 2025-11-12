#include<bits/stdc++.h>
using namespace std;
int t,n,a[100005],b[100005],c[100005],numa,numb,numc,ans,ansa[100005],ansb[100005],ansc[100005];
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>t;
    while(t--)
    {
        numa=numb=numc=ans=0;
        cin>>n;
        for(int i=1;i<=n;i++)cin>>a[i]>>b[i]>>c[i];
        for(int i=1;i<=n;i++)
        {
            if(a[i]>b[i] and a[i]>c[i])ansa[++numa]=a[i]-max(b[i],c[i]),ans+=a[i];
            else if(b[i]>c[i])ansb[++numb]=b[i]-max(a[i],c[i]),ans+=b[i];
            else ansc[++numc]=c[i]-max(a[i],b[i]),ans+=c[i];
        }
        if(numa<=(n>>1) and numb<=(n>>1) and numc<=(n>>1))
        {
            cout<<ans<<'\n';
            continue;
        }
        if(numb>(n>>1))swap(ansa,ansb),swap(numa,numb);
        if(numc>(n>>1))swap(ansa,ansc),swap(numa,numc);
        sort(ansa+1,ansa+numa+1);
        for(int i=1;i<=numa-(n>>1);i++)ans-=ansa[i];
        cout<<ans<<'\n';
    }
    return 0;
}
