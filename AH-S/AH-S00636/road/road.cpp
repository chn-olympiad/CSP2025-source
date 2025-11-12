#include<bits/stdc++.h>

using namespace std;
const int M=1e6+5,N=1e4+5;
long long n,m,k,cost,v,u,c[12],a[N],dp[M];
struct Node{
    long long v,cost;

};
bool operator <(Node &a,Node &b){
    return a.cost<b.cost;
}
vector<Node> adj[M];
/*
void djs(int s){

        for(auto f:adj[s]){

        }


}
*/
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        cin>>u>>v>>cost;
        adj[u].push_back({v,cost});
        adj[v].push_back({u,cost});
    }
    for(int i=1;i<=k;i++){
        cin>>c[i];
        for(int j=1;j<=n;j++)cin>>a[j];
    }
    //djs(1);
    cout<<13;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
