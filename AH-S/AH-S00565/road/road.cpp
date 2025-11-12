#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<queue>
#define ll long long
using namespace std;
int n,m,k;
struct node{
    int u,v,w;
}r[1000010];
int fa[1000010];
ll sum;
void init(){
    for(int i=1;i<=n;i++) fa[i]=i;
}
int find(int x){
    if(fa[x]==x) return x;
    return find(fa[x]);
}
void hb(int x,int y){
    int hx=find(x);
    int hy=find(y);
    if(hx!=hy) fa[hx]=hy;
}
bool cmp(node a,node b){
    return a.w<b.w;
}
void kruscal(){
    init();
    sort(r+1,r+m+1,cmp);
    int cnt=0;
    for(int i=1;i<=m;i++){
        node z=r[i];
        if(find(z.u)!=find(z.v)){
            sum+=z.w;
            hb(z.u,z.v);
            cnt++;
            if(cnt==n-1) break;
        }
    }
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(ll i=1,u,v,w;i<=m;i++){
        scanf("%lld%lld%lld",&r[i].u,&r[i].v,&r[i].w);
    }
    kruscal();
    cout<<sum;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
