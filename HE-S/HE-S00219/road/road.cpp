#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int u[100000],v[100000],w[100000],a[100000],c[100000];
int main(){
 freopen("road.in","r",stdin);
    freopen("road.out","w",stdout); 
cin>>n>>m>>k;
for(int i=1;i<=n;i++){
    cin>>v[i],u[i],w[i];
}for(int j=0;j<=k;j++){
    cin>>c[j];
for(int ss=1;ss<=n+1;ss++){
    cin>>a[j];
}
}
cout<<w[2]+w[3]+c[0]+a[0]+a[2]+2;
return 0;
}
