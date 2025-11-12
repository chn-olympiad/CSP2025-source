#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int n,m,k,c[20];
long long t[N],ans;
struct node{
    long long u,w,v;
}q[N];
bool cmp(node x,node y){
    return x.w<y.w;
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++) cin>>q[i].u>>q[i].v>>q[i].w;
    for(int i=1;i<=k;i++){
        cin>>c[i];
        for(int j=1;j<=n;j++) cin>>t[j];
    }
    sort(q+1,q+m+1,cmp);
    for(int i=1;i<=n-1;i++){
        ans+=q[i].w;
    }
    cout<<ans;
    return 0;
}