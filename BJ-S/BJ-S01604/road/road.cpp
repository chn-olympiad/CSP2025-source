#include<bits/stdc++.h>
using namespace std;
const int maxn =5e6+5;
typedef long long ll;
struct point {
    int u,v;
    ll w;
    bool operator < (const point &abc)const {
        return w>abc.w;
    }
};
priority_queue<point> xq;
int fa[maxn];
int find(int hh)
{
    if(fa[hh]==hh)
        return hh;
    return fa[hh]=find(fa[hh]);
}
ll ans =0;
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,m,k;
    cin>>n>>m>>k;
    for(int i=1;i<=n;++i)
        fa[i]=i;
    for(int i=1;i<=m;++i)
    {
        int x,y;
        ll z;
        cin>>x>>y>>z;
        point rr ={x,y,z};
        xq.push(rr);
    }
    while(!xq.empty())
    {
        int x=xq.top().u;
        int y=xq.top().v;
        ll w=xq.top().w;
        xq.pop();
        int xx=find(x);
        int yy = find(y);
        if(xx!=yy)
        {
            ans+=w;
            fa[xx]=yy;
        }
    }
    cout<<ans;
    return 0;
}
