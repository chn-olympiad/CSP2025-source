#include<bits/stdc++.h>
using namespace std;
int n,m,k;
struct node {
    int u;
    int v;
    int w;
}a[2000005];
bool cmp(node a,node b){
    return a.w<b.w;
}
int f[1055];
int father(int now){
    if(f[now]==now)return now;
    return f[now]=father(f[now]);
}
int main(){
freopen("road.in","r",stdin);
freopen("road.out","w",stdout);
cin>>n>>m>>k;

for(int i=1;i<=1050;i++){
    f[i]=i;
}
for(int i=1;i<=m;i++){
    cin>>a[i].u>>a[i].v>>a[i].w;
}
sort(a+1,a+1+m,cmp);
int daan=0;
for(int i=1;i<=m;i++){
    if(father(a[i].u)!=father(a[i].v)){
        daan+=a[i].w;
        f[father(a[i].u)]=a[i].v;
    }
}
cout<<daan;
return 0;
}
