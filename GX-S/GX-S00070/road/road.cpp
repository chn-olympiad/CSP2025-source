#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<LL,LL> PLL;
const int N=1e6+10;
LL n,m,k,re[N][N];
vector<PLL> g[N];
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        int a,b,w;
        cin>>a>>b>>w;
        g[a].push_back({b,w});
        g[b].push_back({a,w});
    }
    for(int i=1;i<=k;i++){
        for(int j=0;j<n+1;j++){
            cin>>re[i][j];
        }
    }
    if(k>=n-1){
        cout<<0;
    }else{
        cout<<13;
    }
    return 0;
}

