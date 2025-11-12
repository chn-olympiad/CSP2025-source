#include<bits/stdc++.h>
using namespace std;
int n,m,k;
long long ans;
long long u[1000010],v[1000010],w[1000010];
int fa[1000010];
int find(int x){
    if(fa[x]!=fa[fa[x]]) fa[x]=find(fa[x]);
    return fa[x];
}
int mer(int x,int y){
    int fx=find(x),fy=find(y);
    fa[fx]=fy;
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++){
        fa[i]=i;
    }
    for(int i=1;i<=m;i++){
        cin>>u[i]>>v[i]>>w[i];
    }
    sort(w+1,w+1+m);
    for(int i=1;i<=m;i++){
        if(find(u[i])!=find(v[i])){
            mer(u[i],v[i]);
            ans+=w[i];
        }
    }
    cout<<ans;
    return 0;
}
