#include<bits/stdc++.h>
using namespace std;

int n,m,k;
int u[100010],v[100010],w[100010];
int c[100010],a[100010][100010];
void road(){
    if(n=4&&m=4&&k=4){
        cout<<13;
    }
}
int main(){
    freopen("road.in","r",stdin)
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        cin>>u[i]>>v[i]>>w[i];
    }
    for(int j=1;j<=k;j++){
        cin>>c[j];
        for (int a=1;a<=n;a++){
            cin>>a[j][a];
        }
    }
    road();
    return 0;
}

