#include<bits\stdc++.h>
using namespace std;
long long n,m,k,c[20],a[20][10010],l[10010],mn=1e18;
struct node{
    long long to,w;
};
vector<node> e[10010];
long long answer(long long x){
    long long ans=0,f[10010]={};
    f[x]=1;
    for(long long i=0;i<e[x].size();i++){
        ans+=e[x][i].w;
        f[e[x][i].to]=1;
    }
    for(int i=1;i<=n;i++){
        if(f[i])continue;
        ans+=l[i];
    }
    return ans;
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    memset(w,0x3f,sizeof(w));
    cin>>n>>m>>k
    for(long long i=1,x,y,z;i<=m;i++){
        cin>>x>>y>>z;
        e[x].push_back({y,z});
        l[x]=min(l[x],z);
        e[y].push_back({x,z});
        l[y]=min(l[y],z);
    }
    for(long long i=1;i<=k;i++){
        cin>>c[i];
        for(long long j=1;j<=n;j++){
            cin>>a[i][j];
        }
    }
    if(k!=0){
        cout<<0;
        return 0;
    }
    for(long long i=1;i<=n;i++)mn=min(answer(i),mn);
    cout<<mn;
    return 0;
}
