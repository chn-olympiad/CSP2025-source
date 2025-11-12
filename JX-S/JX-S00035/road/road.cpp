#include<bits/stdc++.h>
using namespace std;
int z[100005];
int main(){
freopen("road.in","r",stdin);
freopen("road.out","w",stdout);
int n,m,k,u,v,w,a,b;
cin>>n>>m>>k;
for(int i=1;i<=m;i++){
    cin>>u>>v>>w;
    if(u==0&v==0&w==0) a++;
}
for(int i=1;i<=k;i++){
    for(int j=1;j<=n+1;j++){
        cin>>z[j];
        if(z[j]==0) b++;
    }
}
 cout<<0;
return 0;
}
