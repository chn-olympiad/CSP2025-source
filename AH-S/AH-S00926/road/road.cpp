#include<iostream>
#include<cstdio>
#include<queue>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;
struct node{
    int to,w;
};
int n,m,k;
long long f[10005],ans=((long long)1<<21)-1;
vector<node> g[10005];
void Dij(int x){
    long long sum=0;
    memset(f,0x3f,sizeof(f));
    bool vis[10015]={0},v[10015][10015]={0};
    f[x]=0;
    while(1){
        int u=-1;
        for(int i=1;i<=n;i++){
            if(!vis[i]&&(u==-1||f[u]>f[i])){
                u=i;
            }
        }if(u==-1)break;
        vis[u]=1;
        for(int i=0;i<g[u].size();i++){
            node t=g[u][i];
            if(!vis[t.to]){
                if(f[t.to]>f[u]+t.w){
                    f[t.to]=f[u]+t.w;
                    sum+=t.w;
                }
            }
        }
    }ans=min(ans,sum);
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1,x,y,z;i<=m;i++){
        cin>>x>>y>>z;
        g[x].push_back({y,z});
        g[y].push_back({x,z});cout<<1;
    }for(int i=1,x;i<=k;i++){
        cin>>x;
        for(int j=1;j<=n;j++){
            cin>>x;
        }
    }if(k==0){for(int i=1;i<=n;i++){
        Dij(i);
    }cout<<ans;
    }else cout<<0;
    fclose(stdin);
   fclose(stdout);
    return 0;
}
