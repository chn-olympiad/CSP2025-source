#include<algorithm>
#include<iostream>
#include<cstdio>
using namespace std;
const int N=1e4+5;
const int M=1e6+5;
struct node{
    int u,v,w;
}a[M];
int fa[N],ans;
int findd(int x){
    if(fa[x]==x)return x;
    return fa[x]=findd(fa[x]);
}
void unionn(int x,int y){
    int xx=findd(x);
    int yy=findd(y);
    fa[xx]=fa[yy];
}
bool cmp(node x,node y){
    return x.w<y.w;
}
int main(){
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    int n,m,k;
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++){
        fa[i]=i;
    }
    for(int i=1,u,v;i<=m;i++){
        cin>>a[i].u>>a[i].v>>a[i].w;
    }
    sort(a+1,a+m+1,cmp);
    for(int i=1;i<=m;i++){
        if(findd(a[i].u)!=findd(a[i].v)){
            unionn(a[i].u,a[i].v);
            ans+=a[i].w;
        }
    }
    cout<<ans<<endl;
    return 0;
}
