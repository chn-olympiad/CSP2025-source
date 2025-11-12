#include<bits/stdc++.h>
using namespace std;
int bing[10005],n,m,k,ans;
struct node{
    int u,v,w;
}a[1000005];
bool cmp(node a,node b){
    return a.w<b.w;
}
int f(int x){
    if(bing[x]==x)return x;
    return bing[x]=f(bing[x]);
}
void join(int x,int y){
    int _=f(x),__=f(y);
    bing[_]=__;
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++)cin>>a[i].u>>a[i].v>>a[i].w;
    sort(a+1,a+m+1,cmp);
    for(int i=1;i<=n;i++)bing[i]=i;
    for(int i=1;i<=m;i++){
        if(f(a[i].u)!=f(a[i].v)){ans+=a[i].w;join(a[i].u,a[i].v);}
    }
    cout<<ans;
    fclose(stdin);fclose(stdout);
    return 0;
}
