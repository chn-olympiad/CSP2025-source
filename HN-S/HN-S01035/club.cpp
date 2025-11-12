#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,T,a[N][4],id[N][4];
struct node
{
    int x,d;
};
bool operator <(node a,node b){ return a.d>b.d;}
priority_queue<node> q[4];
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i][1]>>a[i][2]>>a[i][3];
    for(int i=1;i<=n;i++)
    {
        iota(id[i]+1,id[i]+1+3,1);
        sort(id[i]+1,id[i]+1+3,[&](int x,int y){return a[i][x]>a[i][y];});
    }
    int cnt[4]={0,0,0,0};
    for(int i=1;i<=3;i++)
        while(!q[i].empty()) q[i].pop();
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        cnt[id[i][1]]++;
        id[i][0]=1;
        q[id[i][1]].push(node{i,a[i][id[i][id[i][0]]]-a[i][id[i][id[i][0]+1]]});
        ans+=a[i][id[i][1]];
    }
    // cerr<<"?\n";
    // cerr<<q[1].size()<<' '<<q[2].size()<<' '<<q[3].size()<<'\n';
    // cerr<<n<<'\n';
    int l=n/2;
    while(cnt[1]>l||cnt[2]>l||cnt[3]>l)
    {
        int nid;
        if(cnt[1]>l) nid=1;
        else if(cnt[2]>l) nid=2;
        else nid=3;
        // cerr<<nid<<'\n';
        int nx=q[nid].top().x; q[nid].pop();
        // cout<<nx<<' '<<id[nx][0]<<' '<<id[nx][id[nx][0]]<<' '<<id[nx][id[nx][0]+1]<<'\n';
        ans-=a[nx][id[nx][id[nx][0]]];
        cnt[id[nx][id[nx][0]]]--;
        id[nx][0]++;
        ans+=a[nx][id[nx][id[nx][0]]];
        cnt[id[nx][id[nx][0]]]++;
        if(id[nx][0]<3)
            q[id[nx][id[nx][0]]].push(node{nx,a[nx][id[nx][id[nx][0]]]-a[nx][id[nx][id[nx][0]+1]]});
    }
    cout<<ans<<'\n';
    // cout<<T<<'\n';
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin>>T; while(T--) solve();
}