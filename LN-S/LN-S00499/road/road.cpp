#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e4+30;
const int M=1.2e6+10;
int n,m,k,tot=0,fa[N],a[N][20],c[20];
struct node{
    int u,v,w;
    bool operator < (const node &f)const{
        return w<f.w;
    }
}edge[M];
int find(int x){
    if(fa[x]==x){
        return x;
    }else{
        return fa[x]=find(fa[x]);
    }
}
int kruskal(){
    for(int i=1;i<=n;i++) fa[i]=i;
    sort(edge+1,edge+m+1);
    int ans=0,cnt=0;
    for(int i=1;i<=m;i++){
        int u=edge[i].u,v=edge[i].v,w=edge[i].w;
        int fu=find(u),fv=find(v);
        if(fu==fv) continue;
        fa[fu]=fv;cnt++;
        ans+=w;
        if(cnt==n-1) break;
    }
    return ans;
}
signed main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        cin>>edge[i].u>>edge[i].v>>edge[i].w;
    }
    if(k==0){
       cout<<kruskal()<<'\n';
       return 0; 
    }
    for(int i=1;i<=k;i++){
        cin>>c[i];
        for(int j=1;j<=n;j++){
            cin>>a[j][i];
            edge[++m].u=j,edge[m].v=i+n,edge[m].w=a[j][i];
        }
    }
    n+=k;
    int ans=kruskal();
    cout<<ans<<endl;
    return 0;
}
//g++ road.cpp -o road -O2 -std=c++14 -Wall