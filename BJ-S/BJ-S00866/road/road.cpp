
#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,m,k;
    cin>>n>>m>>k;
    int u,v,w[1000005];
    for(int i=1;i<=n;i++) cin>>u>>v>>w[i];
    sort(w+1,w+m+1);
    long long cnt=0;
    for(int i=1;i<=n-1;i++) cnt+=w[i];
    cout<<cnt;
}
