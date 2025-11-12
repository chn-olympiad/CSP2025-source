#include<bits/stdc++.h>
using namespace std;

pair<long long,pair<int,int> > old_edge[1145140];
pair<long long,pair<int,int> > edge[1145140];

int fa[114514];
int sz[114514];
long long c[14];
bool ok[14];    

int find_fa(int x){
    if(fa[x]==x)return x;
    int ans=find_fa(fa[x]);
    if(fa[x]!=ans)sz[fa[x]]-=sz[x];
    fa[x]=ans;
    return ans;
}

void merge(int x,int y){
    x=find_fa(x);y=find_fa(y);
    if(sz[x]<sz[y])fa[x]=y,sz[y]+=sz[x];
    else fa[y]=x,sz[x]+=sz[y];
}

int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(0);

    for(int i=0;i<114514;i++)fa[i]=i,sz[i]=1;
    int n,m,k;
    cin>>n>>m>>k;
    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        old_edge[i]=make_pair(w,make_pair(u,v));
    }
    sort(old_edge,old_edge+m);
    int tot=0;
    for(int i=0;i<m;i++)
        if(find_fa(old_edge[i].second.first)!=find_fa(old_edge[i].second.second)){
            merge(old_edge[i].second.first,old_edge[i].second.second);
            edge[tot]=old_edge[i];
            tot++;
        }   
    
    
    for(int i=1;i<=k;i++){
        cin>>c[i];
        for(int j=1;j<=n;j++){
            int x;
            cin>>x;
            edge[tot++]=make_pair(x,make_pair(i+n,j));
        }
    }

    sort(edge,edge+tot);
    // for(int i=0;i<tot;i++)printf("%d->%d(%lld)\n",edge[i].second.first,edge[i].second.second,edge[i].first);

    long long ans=LONG_LONG_MAX;

    for(int i=0;i<(1<<k);i++){
        for(int j=1;j<=k;j++)ok[j]=(i>>(j-1))&1;
        long long nowans=0,allnode=n;
        for(int j=1;j<=k;j++)if(ok[j])nowans+=c[j],allnode++;
        
        for(int i=0;i<114514;i++)fa[i]=i,sz[i]=1;

        int cnt=0;
        for(int i=0;i<tot;i++)
            if((edge[i].second.first<=n||(edge[i].second.first>n&&ok[edge[i].second.first-n]))&&
                find_fa(edge[i].second.first)!=find_fa(edge[i].second.second)){
                merge(edge[i].second.first,edge[i].second.second);
                cnt++;nowans+=edge[i].first;
                // cout<<edge[i].second.first<<' '<<edge[i].second.second<<' '<<edge[i].first<<' '<<nowans<<endl;
                if(cnt+1==allnode||nowans>ans){break;}
            }
        ans=min(nowans,ans);
        // cout<<i<<' '<<nowans<<endl;
    }
    cout<<ans<<endl;
    return 0;
}