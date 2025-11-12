#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL N=1e4+5;
LL n,m,k,u,v,w,c,a[N],ans;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        cin>>u>>v>>w;
        ans+=w;
    }
    cout<<ans;
    return 0;
}
