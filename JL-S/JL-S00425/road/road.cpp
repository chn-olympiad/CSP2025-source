#include<bits/stdc++.h>
using namespace std;
const int N=1e4+5;
struct node{
    long long u,v,w;
    bool operator <(const node&Q)const{
        return w>Q.w;
    }
};
long long n,m,k,fa[N],lj,c[15],ds[15][N];
priority_queue<node>q;
int fd(int x){
    if(fa[x]!=x)fa[x]=fd(fa[x]);
    return fa[x];
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        q.push({u,v,w});
    }
    for(int i=1;i<=n;i++){
        fa[i]=i;
    }
    for(int i=1;i<=k;i++){
        cin>>c[i];
        for(int j=1;j<=n;j++){
            cin>>ds[i][j];
        }   
    }
    for(int i=1;i<=k;i++){
        if(c[i]==0){
            for(int j=1;j<=n;j++){
                for(int l=j+1;l<=n;l++){
                    q.push({j,l,ds[i][j]+ds[i][l]});
                }
            }
        }
    }
    while(!q.empty()){
        node t=q.top();
        q.pop();
        if(fd(t.u)==fd(t.v))continue;
        fa[fd(t.u)]=fd(t.v);
        lj+=t.w;
    }
    cout<<lj;
    return 0;
}