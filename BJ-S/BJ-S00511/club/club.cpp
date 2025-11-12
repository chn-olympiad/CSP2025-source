#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+5;
struct node
{
    int fi,se,th;
    ll a,b,c;
}pos[N];
priority_queue<pair<ll,ll>> q[3];
ll g[N][3];
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int T;
    cin>>T;
    while(T--)
    {
        int n;
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            ll a,b,c;
            cin>>a>>b>>c;
            g[i][0]=a,g[i][1]=b,g[i][2]=c;
            if(a>=b&&b>=c) pos[i]={0,1,2,a,b,c};
            if(a>=c&&c>=b) pos[i]={0,2,1,a,c,b};
            if(b>=a&&a>=c) pos[i]={1,0,2,b,a,c};
            if(b>=c&&c>=a) pos[i]={1,2,0,b,c,a};
            if(c>=b&&b>=a) pos[i]={2,1,0,c,b,a};
            if(c>=a&&a>=b) pos[i]={2,0,1,c,a,b};
        }
        for(int i=1;i<=n;i++)
        {
            int fi=pos[i].fi,se=pos[i].se;
            if(q[fi].size()+1<=n/2)
            {
                q[fi].push({pos[i].b-pos[i].a,i});
            }
            else
            {
                auto cur=q[fi].top();
                if(pos[i].a-pos[i].b+cur.first>0)
                {
                    q[fi].pop();
                    q[fi].push({pos[i].b-pos[i].a,i});
                    q[pos[cur.second].se].push({pos[cur.second].c-pos[cur.second].b,cur.second});
                }
                else
                {
                    q[se].push({pos[i].b-pos[i].c,i});
                }
            }
        }
        ll ans=0;
        for(int i=0;i<=2;i++)
        {
            while(!q[i].empty())
            {
                ans+=g[q[i].top().second][i];
                q[i].pop();
            }
        }
        cout<<ans<<"\n";
        for(int i=1;i<=n;i++) g[i][0]=g[i][1]=g[i][2]=0;
        for(int i=1;i<=n;i++)
        {
            pos[i].fi=pos[i].se=pos[i].th=0;
            pos[i].a=pos[i].b=pos[i].c=0;
        }
    }
    return 0;
}
