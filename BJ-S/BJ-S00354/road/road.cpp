#include<bits/stdc++.h>
using namespace std;
int fa[10015],sz[10015],c[15];
struct qwq{
    int u,v,w,bl;
}e[1200005];
bool cmp(qwq a,qwq b){
    return a.w<b.w;
}
int find(int x){
    if(fa[x]==x)return x;
    return fa[x]=find(fa[x]);
}
void merge(int a,int b){
    a=find(a);b=find(b);
    if(sz[a]<sz[b])swap(a,b);
    sz[a]+=sz[b];
    fa[b]=a;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,m,k;
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        cin>>e[i].u>>e[i].v>>e[i].w;
        e[i].bl=-1;
    }
    for(int i=1;i<=k;i++){
        cin>>c[i];
        for(int j=1;j<=n;j++){
            int w;
            cin>>w;
            e[m+(i-1)*n+j]={n+i,j,w,i-1};
        }
    }
    sort(e+1,e+m+k*n+1,cmp);
    long long ans=0x3f3f3f3f3f3f3f3f;
    for(int i=0;i<(1<<k);i++){
        long long lans=0;
        int num=0;
        for(int j=1;j<=k;j++){
            if(i&(1<<(j-1))){
                lans+=c[j];
                num++;
            }
        }
        for(int j=1;j<=n+k;j++){
            fa[j]=j;sz[j]=1;
        }
        int cnt=n+num;
        for(int j=1;j<=m+k*n+1;j++){
            if((e[j].bl==-1||(i&(1<<e[j].bl)))&&find(e[j].u)!=find(e[j].v)){
                merge(e[j].u,e[j].v);
                lans+=e[j].w;
                cnt--;
            }
            if(cnt==1||lans>=ans)break;
        }
        ans=min(ans,lans);
    }
    cout<<ans<<endl;
    return 0;
}
//qiu pingceji paodefeikuai.bendi 800ms
