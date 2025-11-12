#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("road.in","r",stdin);
freopen("road.out","w",stdout);
int n,m,k,v[1000000][2],w[1000000],c[10],a[10][10000],s[4][4]=0,cost=0;
cin>>n,m,k;
for(int i=0;i<m;i++){
    for(int x=0;x<2;x++){
        cin>>v[i][x];
    }
    cin>>w[i];
}
for(int j=0;j<k;j++){
    cin>>c[j];
    for(int l=0;l<n;l++){
        cin>>a[j][l];
    }
}
dfs();
cout<<cost<<endl;
return 0;
}
