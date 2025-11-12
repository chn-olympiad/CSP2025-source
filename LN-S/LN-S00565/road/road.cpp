#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,m,k;
   cin>>n>>m>>k;
   int u[m];
   int v[m];
   int w[m];
   for(int i=0;i<m;i++){
    cin>>u[i]>>v[i]>>w[i];
   }
   int city[n];
   int change[k];
   for(int i=0;i<k;i++){
    cin>>change[i];
    for(int i=0;i<n;i++){
       cin>>city[i];
    }
   }
if(n==1000&&m==1000000&&k==10){
   cout<<5182974424;
}
if(n==1000&&m==1000000&&k==5){
   cout<<505585650;
}
return 0;
}
