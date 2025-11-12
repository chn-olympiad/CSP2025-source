#include<bits/stdc++.h>
using namespace std;
int n,m,k,xc[11],s;
bool vis[100001];
long long jg,ans;
vector<int> xl[10001];
vector<pair<int,int> > l[10001];
void dfs(int x){
    if (s==n){
        ans=max(ans,jg);
        return;
    }
    for (int i=1;i<=l.size();i++){
        if (vis[l[x][i].first]){
            vis[l[x][i].first]=1;
            s++;
        }
        jg+=l[x][i].second;
        dfs(vis[l[x][i].first]);
        s--;
        jg-=l[x][i].second;
    }
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for (int i=1;i<=m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        l[a].push_back({b,c});
    }
    for (int i=1;i<=k;i++) cin>>xc[i];
    for (int i=1;i<=n;i++){
        int a;
        cin>>a;
        xl[i].push_back(a);
    }
    dfs(1);
    cout<<ans;
    return 0;
}
