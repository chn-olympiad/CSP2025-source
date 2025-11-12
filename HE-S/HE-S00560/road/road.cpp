#include<bits/stdc++.h>
using namespace std;
int n,m,k,u,v,w,c[15],a[15][10005];
vector<pair<int,int>>e[1000005];
struct mnn{
    int mn,ct;
}minn[10005];
long long ans;
bool flag[15];
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        cin>>u>>v>>w;
        e[u].push_back({v,w});
        e[v].push_back({u,w});
    }for(int i=1;i<=k;i++){
        cin>>c[i];
        for(int j=1;j<=n;j++){
            cin>>a[i][j];
            if(minn[j].mn>a[i][j]){
                minn[j].mn=a[i][j];
                minn[j].ct=i;
            }
        }
    }for(int i=1;i<=n;i++){
        ans+=minn[i].mn;
        if(!flag[minn[i].ct]){
            ans+=c[minn[i].ct];
            flag[minn[i].ct]=1;
        }
    }cout<<ans;
    return 0;
}
