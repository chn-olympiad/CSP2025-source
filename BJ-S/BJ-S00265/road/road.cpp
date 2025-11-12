#include <bits/stdc++.h>
using namespace std;
long long n,m,k,f[20000],c[20000],w[20][20000],ans=1e18;
struct node{
    long long u,v,w;
};
int query(int x){
    if(f[x]<0) return x;
    return f[x]=query(f[x]);
}
void merge(int x,int y){
    x=query(x),y=query(y);
    if(f[x]<f[y]){
        f[x]+=f[y];
        f[y]=x;
    }else{
        f[y]+=f[x];
        f[x]=y;
    }
}
bool cmp(node a,node b){
    return a.w<b.w;
}
vector<node> edge,e;
long long kruskal(int n){
    long long ans=0,cnt=0;
    memset(f,0xff,sizeof(f));
    sort(e.begin(),e.end(),cmp);
    int l1=0,l2=0;
    while(l1<edge.size() && l2<e.size()){
        auto it1=edge[l1],it2=e[l2];
        if(it1.w<it2.w){
            if(query(it1.u)==query(it1.v)){
                l1++;         
            }else{
                merge(it1.u,it1.v);
                ans+=it1.w;
                cnt++;
                if(cnt==n-1) return ans;
            }
        }else{
            if(query(it2.u)==query(it2.v)){
                l2++;
            }else{
                merge(it2.u,it2.v);
                ans+=it2.w;
                cnt++;
                if(cnt==n-1) return ans;
            }
        }
    }
    while(l1<edge.size()){
        auto it1=edge[l1];
        if(query(it1.u)==query(it1.v)){
            l1++;    
        }else{
            merge(it1.u,it1.v);
            ans+=it1.w;
            cnt++;
            if(cnt==n-1) return ans;
        }
    }
    while(l2<e.size()){
        auto it2=e[l2];
        if(query(it2.u)==query(it2.v)){
            l2++;
        }else{
            merge(it2.u,it2.v);
            ans+=it2.w;
            cnt++;
            if(cnt==n-1) return ans;
        }
    }
    return ans;
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        edge.push_back({u,v,w});
    }
    for(int i=0;i<k;i++){
        cin>>c[i];
        for(int j=1;j<=n;j++){
            cin>>w[i][j];
        }
    }
    sort(edge.begin(),edge.end(),cmp);
    for(int s=0;s<(1<<k);s++){
        e.clear();
        long long res=0,cnt=n;
        for(int i=0;i<k;i++){
            if(s&(1<<i)){
                cnt++;
                res+=c[i];
                for(int j=1;j<=n;j++){
                    e.push_back({n+i+1,j,w[i][j]});
                }
            }
        }
        ans=min(ans,kruskal(cnt)+res);
    }
    cout<<ans;
    return 0;
}

