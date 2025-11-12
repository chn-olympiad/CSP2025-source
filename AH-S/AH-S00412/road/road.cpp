#include<bits/stdc++.h>
using namespace std;
struct node{
    int u,v,w;
}a[11000100];
bool cmp(node a,node b){
    return a.w<b.w;
}
int n,m,k,len,newn;
int u,v,w,c[200];
long long ans=0,cnt=0;
int fa[100100];
int in[600100];
void init(){
    for(int i=1;i<=n;i++) fa[i]=i;
}
int get(int x){
    if(fa[x]==x) return x;
    return fa[x]=get(fa[x]);
}
void merge(int x,int y){
    x=get(x); y=get(y);
    if(x!=y) fa[x]=y;
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%d%d%d",&n,&m,&k);
    init();
    for(int i=1;i<=m;i++){
        scanf("%d%d%d",&u,&v,&w);
        len++;
        a[len]={u,v,w};
    }
    for(int i=1;i<=k;i++){
        scanf("%d",&c[i]);
        int w1[100010];
        for(int j=1;j<=n;j++){
            scanf("%d",&w1[j]);
        }
        for(int j=1;j<=n;j++){
            for(int l=j+1;l<=n;l++){
                len++;
                a[len]={j,l,w1[j]+w1[l]+c[i]};
            }
        }
    }
    sort(a+1,a+len+1,cmp);
    for(int i=1;i<=len;i++){
        if(get(a[i].u)!=get(a[i].v)){
            ans+=a[i].w;
            merge(a[i].u,a[i].v);
            //cout<<a[i].u<<" "<<a[i].v<<endl;
        }
    }
    cout<<ans;
    return 0;
}
