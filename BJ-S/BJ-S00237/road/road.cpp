#include<bits/stdc++.h>
using namespace std;
const int N=1e4+10;
int n,m,k;
vector<pair<int,int>> rd[N];
struct village{
    int c,a[N];
}vil[20];
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        rd[u].push_back(make_pair(v,w));
        rd[v].push_back(make_pair(u,w));
    }
    for(int i=1;i<=k;i++){
        cin>>vil[i].c;
        for(int j=1;j<=n;j++){
            cin>>vil[i].a[j];
        }
    }
    int ans=0x3f;
    for(int i=1;i<=k;i++){
        int cnt=0;
        cnt+=vil[i].c;
        for(int j=1;j<=n;j++){
            cnt+=vil[i].a[j];
        }
        ans=min(ans,cnt);
    }
    cout<<ans<<endl;
    return 0;
}