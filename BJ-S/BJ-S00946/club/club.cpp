#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=1e6+10;
const ll inf=1e12;
ll T,n;
ll a[N][4],mxp[N],dif[N],cnt[4];
ll p[N],tot;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>T;
    while(T--)
    {
        cin>>n;
        ll ans=0;
        cnt[1]=cnt[2]=cnt[3]=0;
        for(ll i=1;i<=n;i++)
        {
            cin>>a[i][1]>>a[i][2]>>a[i][3];
            mxp[i]=0;
            dif[i]=inf;
        }
        for(ll i=1;i<=n;i++)
        {
            for(ll j=1;j<=3;j++)
            {
                if(!mxp[i] || a[i][mxp[i]]<a[i][j])
                    mxp[i]=j;
            }
            for(ll j=1;j<=3;j++)
            {
                if(mxp[i]!=j)
                    dif[i]=min(dif[i],a[i][mxp[i]]-a[i][j]);
            }
            cnt[mxp[i]]++;
            ans+=a[i][mxp[i]];
        }
        if(cnt[1]<=n/2 && cnt[2]<=n/2 && cnt[3]<=n/2)
            cout<<ans<<"\n";
        else
        {
            ll pos=0;
            tot=0;
            for(ll i=1;i<=3;i++)
                if(cnt[i]>n/2)
                    pos=i;
            assert(pos);
            for(ll i=1;i<=n;i++)
            {
                if(mxp[i]==pos)
                    p[++tot]=dif[i];
            }
            sort(p+1,p+tot+1);
            for(ll i=1;i<=cnt[pos]-n/2;i++)
                ans-=p[i];
            cout<<ans<<"\n";
        }
    }
    return 0;
}