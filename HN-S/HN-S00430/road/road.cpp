#include <bits/stdc++.h>
using namespace std;
int n,m,k,b[10100];
int find(int sx){
    if(b[sx]!=sx)b[sx]=find(b[sx]);
    return b[sx];
}
struct aaaa{
    int u,w,val;
    bool operator <(const aaaa &a)const{
        return val<a.val;
    }
}e[1000010],v[11][10100];
int ok[10100],cnt;
int kk[11];
long long ans;
int tot=0;
struct bbbb{
    int sx,val,y,u,w;
    bool operator >(const bbbb &a)const{
        return val>a.val;
    }
};
priority_queue<bbbb,vector<bbbb>,greater<bbbb> >q;
signed main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>n>>m>>k;
    for(int x=1;x<=n+k;x++)b[x]=x;
    for(int x=1;x<=m;x++){
        cin>>e[x].u>>e[x].w>>e[x].val;
    }
    sort(e+1,e+m+1);
    int lt=n;
    for(int x=1;x<=m;x++){
        int u=e[x].u,w=e[x].w,val=e[x].val;
        if(find(u)!=find(w)){
            b[find(u)]=find(w);
            ok[++cnt]=x;
            lt--;
            ans+=val;
        }
        if(lt==1)break;
    }
    for(int x=1;x<=k;x++){
        cin>>kk[x];
        for(int y=1;y<=n;y++){
            cin>>v[x][y].val;
            v[x][y].u=y;
            v[x][y].w=n+x;
        }
        sort(v[x]+1,v[x]+n+1);
    }
    int mx=(1ll<<k);
    for(int x=1;x<mx;x++){
        while(!q.empty())q.pop();
        long long sum=0;
        tot=0;
        int lc=n;
        for(int y=1;y<=k;y++){
            if((x>>(y-1))&1){
                sum+=kk[y];
                lc++;
                q.push({1,v[y][1].val,y,v[y][1].u,v[y][1].w});
            }
        }
        q.push({1,e[ok[1]].val,0,e[ok[1]].u,e[ok[1]].w});
        for(int y=1;y<=n+k;y++)b[y]=y;
        while(!q.empty()){
            bbbb sx=q.top();
            q.pop();
            int u=sx.u,w=sx.w,val=sx.val;
            //if(x==1)cout<<u<<' '<<w<<' '<<val<<'\n';
            if(find(u)!=find(w)){
                b[find(u)]=find(w);
                sum+=val;
                lc--;
            }
            if(lc==1||sum>ans)break;
            if(sx.y==0){
                if(sx.sx<n-1)q.push({sx.sx+1,e[ok[sx.sx+1]].val,sx.y,e[ok[sx.sx+1]].u,e[ok[sx.sx+1]].w});
            }
            else{
                if(sx.sx<n){
                    q.push({sx.sx+1,v[sx.y][sx.sx+1].val,sx.y,v[sx.y][sx.sx+1].u,v[sx.y][sx.sx+1].w});
                }
            }
        }
        ans=min(ans,sum);
    }
    cout<<ans<<'\n';
}