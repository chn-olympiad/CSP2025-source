#include<bits/stdc++.h>
using namespace std;
int u[1000010],v[1000010],w[1000010];
int a[20];
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);

    int n,m,k;
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++)
        cin>>u[i]>>v[i]>>w[i];
    int c;
    cin>>c;
    for(int i=1;i<=k;i++)
        cin>>a[i];
    long long ans=0;
    for(int i=1;i<=m;i++){
        ans+=w[i];
    }
    cout<<ans;
    return 0;
}
