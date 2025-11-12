#include<bits/stdc++.h>
using namespace std;

int a2[1034855];
int fa[193948];
int ans;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,m,k;
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        int u,v,w;
        cin>>u>>v>>w;

        ans+=w;
    }
    int cnt=1;
    for(int i=1;i<=k;i++){
        int u;
        cin>>u;

        cnt++;
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
