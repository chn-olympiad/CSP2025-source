#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
struct nd{
    int u,v,w;
}g[N];
int main(){
freopen("road.in","r",stdin);
freopen("road.out","w",stdout);
int n,m,k,a[1000010];
cin>>n>>m>>k;
for(int i=1;i<=m;i++){
    cin>>g[i].u>>g[i].v>>g[i].w;
}
for(int j=1;j<=k;j++){
    cin>>a[j]>>g[i+j].u>>g[i+j].v>>g[i+j].w;
}
for(int i=1;i<=m+k;i++){
    if(minn>g[i].u){
        minn=g[i].u;
    }
    if(minnn>g[i].v){
        minnn=g[i].v;
    }
    if(minnnn>g[i].w){
        minnnn=g[i].w;
    }
}
cout<<minn+minnn+minnnn;
return 0;
}
