
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define vt vector<int>
#define vl vector<long long>
const int N=1e6+10;
int n,m,k,ans=0;
vt q[N];
void dfs(int now,int fa){

}
int main(){
    freopen("road.in","r",stdin);//please open it
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(false);cin.tie(0);
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++){
        int u,v;
        cin>>u>>v;
        q[u].push_back(v);
        q[v].push_back(u);
    }
    dfs(1,0);
    cout<<minn;
    return 0;
}
