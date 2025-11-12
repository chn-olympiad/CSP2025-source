#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,m,k,a[20],s[20][10010],fa[10020];
struct line{
    int u,v,w;
    line(){}
    line(int uu,int vv,int ww){u=uu,v=vv,w=ww;}
};
bool cmp(line x,line y){return x.w<y.w;}
int find(int x){
    if(fa[x]==x)
        return x;
    return fa[x]=find(fa[x]);
}
int main(){
	freopen("road.in","r",stdin);freopen("road.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>m>>k;vector<line> G,g;
    for(register int i=1;i<=m;i++){
        int u,v,w;cin>>u>>v>>w;
        G.push_back(line(u,v,w));
    }
    for(register int i=1;i<=k;i++){
        cin>>a[i];
        for(register int j=1;j<=n;j++)
            cin>>s[i][j];
    }
    sort(G.begin(),G.end(),cmp);int num=n;
    for(int i=1;i<=n+k;i++)
    	fa[i]=i;
    for(line x:G){
        if(num==1)
            break;
        int fx=find(x.u),fy=find(x.v);
        if(fx!=fy)
            num--,fa[fx]=fy,g.push_back(x);
    }
    ll ans=0x7f7f7f7f7f7f7f7f;
    for(register int i=0;i<(1<<k);i++){
        vector<line> h;h=g;num=n;ll now=0;
        for(register int j=1;j<=k;j++)
            if((i>>(j-1))&1){
                now+=a[j];num++;
                for(register int l=1;l<=n;l++)
                    h.push_back(line(n+j,l,s[j][l]));
            }
        if(now>=ans)
            continue;
        for(register int j=1;j<=n+k;j++)
            fa[j]=j;
        sort(h.begin(),h.end(),cmp);
        for(line x:h){
            if(num==1||now>=ans)
                break;
            int fx=find(x.u),fy=find(x.v);
            if(fx!=fy)
                num--,now+=x.w,fa[fx]=fy;
        }
        ans=min(ans,now);
    }
    return cout<<ans,0;
}