#include<bits/stdc++.h>
using namespace std;
#define int long long
int t,n;
struct P{int p,d;}q[5][500000],c[5];
int cnt[5],ans;
bool cmp(P aa,P bb){return aa.d<bb.d;}
signed main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    scanf("%lld",&t);
    while(t--)
    {
        memset(q,0,sizeof q);
        memset(cnt,0,sizeof cnt);
        ans=0;
        scanf("%lld",&n);
        for(int i=1;i<=n;i++)
        {
            c[0].p=0,c[1].p=1,c[2].p=2;
            scanf("%lld%lld%lld",&c[0].d,&c[1].d,&c[2].d);
            sort(c,c+3,cmp);
            ans+=c[2].d;
            q[c[2].p][++cnt[c[2].p]]={cnt[c[2].p],c[2].d-c[1].d};
        }
        for(int i=0;i<3;i++)
        {
            if(cnt[i]>(n/2))
            {
                sort(q[i]+1,q[i]+cnt[i]+1,cmp);
                for(int j=1;j<=(cnt[i]-n/2);j++)
                {
                    ans-=q[i][j].d;
                }
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}
