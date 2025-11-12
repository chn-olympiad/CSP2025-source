#include<bits/stdc++.h>
using namespace std;
int n,m,k;
const int MAXN=1e5+5;
int u,v,w[MAXN],ans;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++)cin>>u>>v>>w[i];
    sort(w+1,w+m+1);
    for(int i=1;i<=n-1;i++){
        ans+=w[i];
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;

}
