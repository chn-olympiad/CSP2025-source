#include<bits/stdc++.h>
using namespace std;
const int N=1e6+1;
int n,m,k,ans;
struct node{
    int u,v,w;
}s[N];
bool cmp(node a,node b){
    return a.w<b.w;
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        s[i]={u,v,w};
    }
    sort(s+1,s+1+m,cmp);
    for(int i=1;i<n;i++){
        ans+=s[i].w;
    }
    cout<<ans;
    return 0;
}
