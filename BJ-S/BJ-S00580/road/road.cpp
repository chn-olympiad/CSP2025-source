#include<bits/stdc++.h>
using namespace std;
const int N=2e4+10,M=2e6+10;;
int n,m,k,f[N],cnt,ans;
struct Node{
    int u,v,w;
    bool operator<(const Node &x)const{
        return this->w<x.w;
    }
}e[M];
int fd(int x){
    if(f[x]==x)return x;
    f[x]=fd(f[x]);
    return f[x];
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=n+k;i++)f[i]=i;
    for(int i=1;i<=m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        e[++cnt].u=a,e[cnt].v=b,e[cnt].w=c;
    }
    sort(e+1,e+cnt+1);
    for(int i=1;i<=m;i++){
        int a=e[i].u,b=e[i].v,c=e[i].w;
        if(fd(a)!=fd(b))ans+=c;
        f[a]=b;
    }
    cout<<ans;
    return 0;
}
