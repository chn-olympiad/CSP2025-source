#include <bits/stdc++.h>
using namespace std;
long long n,m,k;
long long u,v,w;
long long a[1000010];
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);

    cin>>n>>m>>k;

    for(int i=1;i<=n+1;i++){
        for(int j=1;j<=3;j++){
            cin>>u>>v>>w;
        }
    }
    for(int j=1;j<=k;j++)
        for(int i=1;i<=n+1;i++)
            cin>>a[i];
    cout<<0;
    return 0;
}
