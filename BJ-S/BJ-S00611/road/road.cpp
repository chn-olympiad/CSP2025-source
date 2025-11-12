#include<bits/stdc++.h>
using namespace std;
const int N=1e4+15;
int n,m,k;
int fa[N],cnt;
int price[12];
int a[12][N];
long long ans;
long long nowans;
struct road
{
    int u,v,w;
    bool operator <(const road& r1) const
    {
        return r1.w<w;
    }
};
priority_queue<road>basic;
priority_queue<road>q;
int Find(int x){
    if(x!=fa[x])
        fa[x]=Find(fa[x]);
    return fa[x];
}
bool join(int x,int y)
{
    int fax=Find(fa[x]),fay=Find(fa[y]);
    if(fax!=fay)
        return true;
    else
        return false;
}
void solve()
{
    for(int i=1;i<=n+k;i++)
        fa[i]=i;
    int j=0;
    while(!q.empty())
    {
        road t=q.top();
        q.pop();
        if(join(t.u,t.v)){
            fa[t.u]=t.v;
            nowans+=t.w;
            j++;
        }
        if(j==n+cnt-1)
            break;
    }
    while(!q.empty())
        q.pop();
}
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1,u,v,w;i<=m;i++){
        cin>>u>>v>>w;
        basic.push((road){u,v,w});
    }
    for(int i=1;i<=k;i++){
        cin>>price[i];
        for(int j=1;j<=n;j++){
            cin>>a[i][j];
        }
    }
    q=basic;
    solve();
    ans=nowans;
    for(int s=1;s<=(1<<k)-1;s++){
        q=basic;
        nowans=0;cnt=0;
        for(int i=0;i<k;i++){
            if(s&(1<<i)){
                nowans+=price[i+1];
                cnt++;
                for(int j=1;j<=n;j++){
                    q.push((road){i+n+1,j,a[i+1][j]});
                }
            }
        }
        solve();
    //    cout<<nowans<<endl;
        ans=min(ans,nowans);
    }
    cout<<ans;
    return 0;
}
