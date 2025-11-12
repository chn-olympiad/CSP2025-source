#include<bits/stdc++.h>
using namespace std;
long long n,m,u[10005],v[10005],w[1000005],c[11],a[11][10005];
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m;
    for (int i=1;i<=m;i++){
        cin>>u[i]>>v[i]>>w[i];
        if (w[i]>w[i+1]){
            int t=w[i];
            w[i]=w[i+1];
            w[i+1]=t;
        }
    }
    int ans=0;
    for (int i=1;i<=6;i++){
        ans+=w[i];
    }
    cout<<ans;
    return 0;
}
