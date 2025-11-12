#include<bits/stdc++.h>
using namespace std;
struct edge{
    int u,v,c,pos;
}h[1000005],hh[200005];
int tot;
bool cmp(edge a,edge b){
    return a.c<b.c;
}
int fa[10015];
int find(int x){
    if(fa[x]==x)return x;
    else return fa[x]=find(fa[x]);
}
void add(int x,int y){
    fa[find(x)]=y;
}
int n,m,k;
int w[15];
int val[15][10005];
long long ans=0x3f3f3f3f3f3f3f3f,anser=0;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    //cout<<n<<" "<<m<<" "<<k<<endl;
    for(int i=1;i<=n;i++)fa[i]=i;
    for(int i=1;i<=m;i++){
        cin>>h[i].u>>h[i].v>>h[i].c;
    }
    sort(h+1,h+m+1,cmp);
    for(int i=1;i<=m;i++){
        int u=h[i].u,v=h[i].v,c=h[i].c;
        if(find(u)==find(v))continue;
        hh[++tot].u=u,hh[tot].v=v,hh[tot].c=c;
       // cout<<u<<" "<<v<<" "<<c<<endl;
        add(u,v);
    }
    for(int i=1;i<=k;i++){
        cin>>w[i];
        for(int j=1;j<=n;j++){
            cin>>val[i][j];
            hh[++tot].u=i+n,hh[tot].v=j,hh[tot].c=val[i][j];
            hh[tot].pos=i;
        }
    }
    sort(hh+1,hh+tot+1,cmp);
    /*for(int i=1;i<=tot;i++){
        cout<<hh[i].u<<" "<<hh[i].v<<" "<<hh[i].c<<" "<<hh[i].pos<<endl;
    }*/
    for(int s=0;s<=(1<<k)-1;s++){
        anser=0;
        for(int i=1;i<=k;i++){
            //ut<<s<<" "<<(1<<(k-1))<<" "<<(s&(1<<(k-1)))<<endl;
            if(s&(1<<(i-1))){
                anser+=w[i];
            }
        }
        for(int i=1;i<=n+k;i++)fa[i]=i;
        for(int i=1;i<=tot;i++){
            if(hh[i].pos!=0 && ((1<<(hh[i].pos-1))&s)==0)continue;
            int u=hh[i].u,v=hh[i].v,c=hh[i].c;
            //cout<<s<<" "<<u<<" "<<v<<" "<<c<<" "<<anser<<endl;
            if(find(u)==find(v))continue;
          //  hh[++tot].u=u,hh[tot].v=v,hh[tot].c=c;
            add(u,v);
            anser+=c;
        }
        //cout<<anser<<endl;
        ans=min(ans,anser);
        //tot=n-1;
    }
    cout<<ans;
}
