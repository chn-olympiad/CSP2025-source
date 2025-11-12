#include<bits/stdc++.h>
using namespace std
const int N=1e5;
int n,m,k,u[N],v[N],w[N],c[N][100000],first=0,second=0,sheng=0,t;
int main(){
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        cin>>u[i]>>v[i]>>w[i]<<endl;
        if(w[i]<w[i-1]){
            first=w[i];
        }
        if(w[i]>min&&w[i]<w[i-1]){
            second=w[i];
        }
    }
    for(int i=1;i<=n+1;i++){
      for(int j=1;j<=k;j++){
        cin>>c[i][j];
        t=min(c[i][j],c[i][j-1]);
    }
    sheng=min(c[i],c[i-1]);
}
    cout<<t+sheng+first+second;
    return 0;
}
