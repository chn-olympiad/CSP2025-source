#include<bits/stdc++.h>
#define int long long
using namespace std;
struct edge{
    int u,v,w;
    friend bool operator< (const edge &a,const edge &b){
        return a.w<b.w;
    }edge(){}
    edge(int _u,int _v,int _w){
        u=_u,v=_v,w=_w;
    }
}ed[1000005];
int c[11],a[11][10005];
vector<edge>vc;
int fa[10015],size[10015],cnt;
void init(int n){
    cnt=n;
    for(int i=1;i<=n;++i)fa[i]=i,size[i]=1;
}int find(int x){
    return (x==fa[x]?x:fa[x]=find(fa[x]));
}void merge(int x,int y){
    x=find(x),y=find(y);
    if(x==y)return;
    if(size[x]>size[y])swap(x,y);
    fa[y]=x;size[x]+=size[y];
    return;
}signed main(){
    int n,m,k,out=LLONG_MAX;
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;++i){
        cin>>ed[i].u>>ed[i].v>>ed[i].w;
    }sort(ed+1,ed+m+1);
    for(int i=1;i<=k;++i){
        cin>>c[i];
        for(int j=1;j<=n;++j)cin>>a[i][j];
    }int csh=0;
    while(csh<(1<<k)){
        vc.clear();
        int ans=0,cshs=0;
        for(int i=1;i<=k;++i){
            if((csh>>(i-1))&1){
                ans+=c[i];++cshs;
                for(int j=1;j<=n;++j){
                    vc.push_back(edge(n+cshs,j,a[i][j]));
                }
            }
        }sort(vc.begin(),vc.end());init(n+cshs);
        for(int i=0,j=1;cnt>1&&(i<vc.size()||j<=m);){
            while(i<vc.size()&&find(vc[i].u)==find(vc[i].v))i++;
            while(j<=m&&find(ed[j].u)==find(ed[j].v))j++;
            if(i<vc.size()&&vc[i]<ed[j]){
                ans+=vc[i].w;
                merge(vc[i].u,vc[i].v);
                ++i;--cnt;
            }else{
                ans+=ed[j].w;
                merge(ed[j].u,ed[j].v);
                ++j;--cnt;
            }
        }if(cnt==1)out=min(out,ans);
        csh++;
    }cout<<out<<endl;
    return 0;
}