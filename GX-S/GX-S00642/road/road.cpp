#include<bits/stdc++.h>
using namespace std;
struct edge{
    int u,v,w;
};
edge m[1200005];
int cnt;
int f[10005];
long long ans;
int ch(int u){
    if(f[u]!=u) return f[u]=ch(f[u]);
    return u;
}
bool cmp(edge a,edge b){
    return a.w<b.w;
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,M,k;
    cin>>n>>M>>k;
    for(int i=1;i<=n;i++) f[i]=i;
    for(int i=1;i<=M;i++){
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        m[i]=(edge){u,v,w};
    }
    sort(m+1,m+M+1,cmp);
    cnt=M;
    for(int i=1;i<=M;i++){
        if(ch(m[i].u)!=ch(m[i].v)){
            ans+=m[i].w;
            cnt--;
            f[ch(m[i].u)]=ch(m[i].v);
        }
        if(cnt<=0) break;
    }
    cout<<ans;
    return 0;
}
