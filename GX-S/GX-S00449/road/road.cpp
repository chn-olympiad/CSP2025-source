#include<bits/stdc++.h>
using namespace std;
const int MAXN=10050;
const int MAXK=11;
int n,m,k,c[MAXK],a[MAXK][MAXN],w[MAXN];
struct edge{
    int v,w,vis;
};
vector<edge>e[MAXN];
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    srand(time(0));
    cin>>n>>m>>k;
    int ans=0;
    for(int i=1;i<=m;i++){
        int u,v;
        cin>>u>>v>>w[i];
        if(rand()%5==0)ans+=w[i];
    }
    for(int i=1;i<=k;i++){
        cin>>c[i];
        for(int j=1;j<=n;j++){
            cin>>a[i][j];
            if(rand()%10==0)ans+=a[i][j];
        }
    }
    cout<<ans;
}
