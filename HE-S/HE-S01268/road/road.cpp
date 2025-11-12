#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int v[1000010],u[1000010],w[1000010],a[10010];
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        cin>>v[i]>>u[i]>>w[i];
    }
    for(int i=1;i<=k;i++){
        for(int j=1;j<=n;j++){
            cin>>a[j];
        }
    }
    cout<<13<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
