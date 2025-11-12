#include<bits/stdc++.h>
using namespace std;
#define int long long
struct side{
    int x,y,w;
};
vector<side>v;
int fa[10010];
int find(int x){
    if(fa[x]==x)return x;
    fa[x]=find(fa[x]);
    return fa[x];
}
void merge(int x,int y){
    fa[find(x)]=find(y);
}
bool cmp(side x,side y){
    return x.w<y.w;
}
long long ku(){
    sort(v.begin(),v.end(),cmp);
    long long ans=0;
    for(int i=0;i<v.size();i++){
        side k=v[i];
        // cout<<k.x<<" "<<k.y<<" "<<k.w<<"\n";
        // cout<<find(k.x)<<" "<<find(k.y)<<"\n";
        if(find(k.x)!=find(k.y))ans+=k.w,merge(k.x,k.y);
    }
    return ans;
}
int num[11][1010],c[1010];
int e[1010][1010];
int n;
int vis[1010];
bool dis[1010];
long long prim(){
    memset(vis,0x7f,sizeof(vis));
    memset(dis,0,sizeof(dis));
    queue<int>q;
    vis[1]=0,dis[1]=1;
    q.push(1);
    long long ans=0;
    while(!q.empty()){
        int k=q.front();
        q.pop();
        int Min=1e9,id=-1;
        for(int i=1;i<=n;i++)
            if(dis[i]==0){
                vis[i]=min(vis[i],e[k][i]);
                if(Min>vis[i])Min=vis[i],id=i;
            }
        if(id==-1)continue;
        dis[id]=1,ans+=Min,q.push(id);
    }
    return ans;
}
side se[1000010];
signed main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int m,k;
    cin>>n>>m>>k;
    if(k==0){
        for(int i=1;i<=m;i++){
            int x,y,z;
            cin>>x>>y>>z;
            v.push_back(side{x,y,z});
        }
        for(int i=1;i<=n;i++)
            fa[i]=i;
        cout<<ku();
    }else{
        memset(e,0x7f,sizeof(e));
        for(int i=1;i<=m;i++){
            int x,y,z;
            cin>>x>>y>>z;
            se[i].x=x,se[i].y=y,se[i].w=z;
        }
        bool flag2=0;
        for(int i=1;i<=k;i++){
            cin>>c[i];
            if(c[i]>0)flag2=1;
            for(int j=1;j<=n;j++)
                cin>>num[i][j];
        }
        if(!flag2){
            for(int p=1;p<=m;p++)
                e[se[p].x][se[p].y]=min(e[se[p].x][se[p].y],se[p].w),e[se[p].y][se[p].x]=min(e[se[p].y][se[p].x],se[p].w);
            for(int p=1;p<=k;p++)
            for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                e[i][j]=min(e[i][j],num[p][i]+num[p][j]);
            cout<<prim()<<"\n";
        }else{
            long long ans=1e18;
            for(int x=0;x<(1<<k);x++){
                int sum=0;
                memset(e,0x7f,sizeof(e));
                for(int p=1;p<=m;p++)
                    e[se[p].x][se[p].y]=min(e[se[p].x][se[p].y],se[p].w),e[se[p].y][se[p].x]=min(e[se[p].y][se[p].x],se[p].w);
                for(int y=1;y<=k;y++)
                    if(x&(1<<(y-1))){
                        for(int i=1;i<=n;i++)
                            for(int j=1;j<=n;j++)
                                e[i][j]=min(e[i][j],num[y][i]+num[y][j]);
                        sum+=c[y];
                    }
                ans=min(ans,prim()+sum);
            }
            cout<<ans;
        }
    }
    return 0;
}