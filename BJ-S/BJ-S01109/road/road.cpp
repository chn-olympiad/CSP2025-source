#include<bits/stdc++.h>
using namespace std;
int fa[10010],c[10010],a[10010];
struct node {
    int u,v,w;
}mp[1000010];
bool cmp(node x,node y) {
    return x.w<y.w;
}
int gr(int x) {
    if(x==fa[x]) {
        return fa[x];
    }
    return gr(fa[x]);
}
bool vis[10010];
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,m,k,uu,vv,ww;
    cin>>n>>m>>k;
        for(int i=1;i<=n;i++) {
            fa[i]=i;
        }
        for(int i=1;i<=m;i++) {
            cin>>mp[i].u>>mp[i].v>>mp[i].w;
        }
        sort(mp+1,mp+m+1,cmp);
        int cnt=0;
        long long ans=0;
        for(int i=1;i<=m;i++) {
            if(gr(mp[i].u)!=gr(mp[i].v)) {
                ans+=mp[i].w;
                fa[gr(mp[i].u)]=fa[gr(mp[i].v)];
                cnt++;
            }
            if(cnt==n-1) {
                break;
            }
        }
        cout<<ans;

    return 0;
}