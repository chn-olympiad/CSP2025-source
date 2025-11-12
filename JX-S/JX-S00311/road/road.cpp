#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,m,k;
ll ans;
const int maxn=1e4+5,maxm=1e6+5;
int fa[maxn];
int f(int u){
    if(fa[u]==u)return u;
    else return fa[u]=f(fa[u]);
}
void mer(int u,int v){
    int fu=f(u),fv=f(v);
    fa[fv]=fu;
    return;
}
struct node{
    int u,v,w;
    void in(){
        scanf("%d%d%d",&u,&v,&w);
    }
    void out(){
        printf("%d %d %d\n",u,v,w);
    }
}a[maxm];
bool cmp(node e1,node e2){
    return e1.w<e2.w;
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%d%d%d",&n,&m,&k);
    if(k==0){
        for(int i=1;i<=n;i++)fa[i]=i;
        for(int i=1;i<=m;i++)a[i].in();
        sort(a+1,a+m+1,cmp);
        //for(int i=1;i<=m;i++)a[i].out();
        for(int i=1;i<=m;i++){
            if(f(a[i].u)!=f(a[i].v)){
                ans+=a[i].w;
                mer(a[i].u,a[i].v);
            }
        }
        printf("%lld\n",ans);
    }
    else {
        printf("0");
    }
    return 0;
}
