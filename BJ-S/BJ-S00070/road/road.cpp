#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
struct node{
    int u,v,w;
}a[N];
int b[25][N];
int c[N];
int fa[N];
int use[30];
int find(int x){
    if(fa[x]==x) return x;
    else return fa[x]=find(fa[x]);
}
bool cmp(node a,node b){
    return a.w<b.w;
}
bool cmp2(int a,int b){
    return a>b;
}
long long ans;
int n,m,k;
void kk(){
    for(int i=1;i<=2*m;i++){
        int x=find(a[i].u);
        int y=find(a[i].v);
        if(x!=y){
            fa[y]=x;
            ans+=a[i].w;
        }
    }
}
void kk2(){
    for(int i=1;i<=2*m;i++){
        int x=find(a[i].u);
        int y=find(a[i].v);
        if(x!=y){
            fa[y]=x;
            ans+=a[i].w;
            for(int i=1;i<=k;i++){
                if(b[i][a[i].u]+b[i][a[i].v]<a[i].w){
                    ans-=(a[i].w-b[i][a[i].u]-b[i][a[i].v]);
                    b[i][a[i].u]=b[i][a[i].v]=INT_MAX;
                }
            }
        }
    }
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    if(k==0){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    for(int i=1;i<=m;i++){
        cin>>a[i].u>>a[i].v>>a[i].w;
        a[i+m].u=a[i].v;
        a[i+m].v=a[i].u;
        a[i+m].w=a[i].w;
    }
    for(int i=1;i<=2*m;i++) fa[i]=i;
    sort(a+1,a+1+2*m,cmp);
    kk();
    cout<<ans;
    }
    else{
        ios::sync_with_stdio(false);
        cin.tie(0);cout.tie(0);
        for(int i=1;i<=m;i++){
            cin>>a[i].u>>a[i].v>>a[i].w;
            a[i+m].u=a[i].v;
            a[i+m].v=a[i].u;
            a[i+m].w=a[i].w;
        }
        for(int i=1;i<=k;i++){
            cin>>c[i];
            for(int j=1;i<=m;j++){
                cin>>b[i][j];
            }
            sort(b[i]+1,b[i]+1+m,cmp2);
        }
        for(int i=1;i<=2*m;i++) fa[i]=i;
        kk2();
        cout<<ans;
    }
    return 0;
}
