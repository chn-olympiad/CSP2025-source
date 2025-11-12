#include<bits/stdc++.h>
using namespace std;
long long n,m,k,u1,v1,w1,ans,f;
struct edge{
    long long u,v,w;
    bool operator>(const edge& b)const{
        return w>b.w;
    }
};
long long a[15][10010],c[15];
long long idx[10010],fa[10010];
bool flag;
priority_queue<edge,vector<edge>,greater<edge>> q;
long long find(long long x){
    if(fa[x]==x){
        return x;
    }
    return find(fa[x]);
}
void merge(long long x,long long y){
    fa[find(x)]=find(y);
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(long long i=1;i<=m;i++){
        cin>>u1>>v1>>w1;
        q.push({u1,v1,w1});
    }
    for(long long i=1;i<=k;i++){
        cin>>c[i];
        for(long long j=1;j<=n;j++){
            cin>>a[i][j];
        }
    }
    for(long long i=1;i<=n;i++){
        fa[i]=i;
    }
    while(!q.empty()){
        merge(q.top().u,q.top().v);
        ans+=q.top().w;
        q.pop();
        f=find(1);
        flag=false;
        for(long long i=2;i<=n;i++){
            if(find(i)!=find(1)){
                flag=true;
            }
        }
        if(!flag){
            break;
        }
    }
    cout<<ans;
    return 0;
}
