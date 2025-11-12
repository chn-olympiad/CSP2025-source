#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10;
int n,m,k;
struct edge{
    int u,v,w;
}a[N];
int fa[N];
bool cmp(edge x,edge y){
    return x.w<y.w;
}
int findfa(int x){
    if(fa[x]==x)return x;
    else return fa[x]=findfa(fa[x]);
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin.tie(0);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        cin>>a[i].u>>a[i].v>>a[i].w;
    }
    for(int i=1;i<=k;i++){
        int x;
        cin>>x;
        for(int j=1;j<=n;j++){
            m++;
            a[m].u=i;
            a[m].v=j;
            cin>>a[m].w;
        }
    }
    //for(int i=1;i<=m;i++)cout<<a[i].u<<" "<<a[i].v<<" "<<a[i].w<<"\n";
    sort(a+1,a+m+1,cmp);
    for(int i=1;i<=n;i++)fa[i]=i;
    long long ans=0;
    for(int i=1;i<=m;i++){
        int findu=findfa(a[i].u);
        int findv=findfa(a[i].v);
        if(findu==findv)continue;
        //cout<<a[i].u<<" "<<a[i].v<<" "<<a[i].w<<"\n";
        fa[findu]=findv;
        ans+=a[i].w;
    }
    cout<<ans;
    return 0;
}
