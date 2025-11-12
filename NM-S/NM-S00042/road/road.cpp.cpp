#include<iostream>
using namespace std;
int main(){
freopen("road.in","r","stdin");
freopen("road.out","w","stdout");
int n,m,k,u,n,l,b;
int a[10000][10000];

int f[1000];
int f[1000];
int y[1000][1000];
int g[1000];
cin>>n>>m>>k;
for(int i=1;i++;i<=m){
cin>>u>>n>>l;
if(l<=a[u][n]){

a[u][n]=a[u][n];

}
if(l>a[u][n]){

a[u][n]=l;
}
if(l<=a[n][u]){

a[n][u]=a[n][u];

}
if(l>a[n][u]){
a[n][u]=l;
}
a[u][n]=l;
}
for(int o=1;o++;o<=k){
for(int i=1;i++;i<=k){

cin>>f[i];
cin>>y[i][o];
}
}
for(int i=1;i++;i<=n){
for(int o=1;o++;o<=n){
if(a[i][i+1]>0){
if(a[i][i+1]>f[o]+y[i][o]+y[i+1][o]){
g[i]=a[i][i+1]=f[o]+y[i][o]+y[i+1][o];
}
if(f[o]+y[i][o]+y[i+1][o]>a[i][i+1]){
g[i]=a[i][i+1];
}
else g[i]=f[o]+y[i][o]+y[i+1][o];
}

}

}
b=g[1];
for(q=3;q++;q<=n+1){

b=b+g[q-1];

}
cout<<b;



}
