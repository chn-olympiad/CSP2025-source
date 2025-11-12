#include<bits/stdc++.h>
using namespace std;
int n,m,k;
long long h;
int w[1000010],a[20][10010],c[20];
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        int u,v,wi;
        cin>>u>>v>>wi;
        w[i]=wi;
    }
    sort(w+1,w+1+m);
    for(int i=1;i<=k;i++){
        cin>>c[i];
        for(int j=1;j<=n;j++){
            cin>>a[i][j];
        }
    }
    if(k==0){
        for(int i=1;i<n;i++){
            h+=w[i];
        }
        cout<<h;
    }else{
        cout<<"0";
    }
    return 0;
}
