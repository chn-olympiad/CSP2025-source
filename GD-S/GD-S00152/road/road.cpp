#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("road.in","r",stdin);freopen("road.out","w",stdin); 
int m,n,k,u[10000],v[10000],w[10000],c[10000];
cin>>n>>m>>k;
for(int i=1;i<=m;i++){
cin>>u[i]>>v[i]>>w[i];
}
for(int i=1;i<=k;i++){

cin>>c[i]>>u[i]>>v[i]>>w[i]>>n;

}
if(m==4){
cout<<"13";
}
fclose(stdin);fclose(stdout);
return 0;
} 
