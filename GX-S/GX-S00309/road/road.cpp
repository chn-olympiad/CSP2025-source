#include<bits/stdc++.h>
using namespace std;

long long n,m,k,u[10000100],w[10000100],v[10000100],c[10000100],a[50][10000100],tot,go,ans;
long long vc[1000100],vx[1000100];
/*bool ltx(int n){



}*/
/*int gomin(int p){
    //if(p>k*n+m)return;
    vc[p]=1;
     if(v[p]>n||u[p]>n)vx[p]=1;
    int tmp=900000000;
for(int i=1;i<=tot;i++){
        if(v[i]>n||u[i]>n)vx[i]=1,vc[i]=1;
    if((u[i]==p||v[i]==p)&&(!vc[i]))
   {
       if(w[i]<tmp){
        go=i;
        tmp=w[i];


       }


   }

ans+=w[go];
gomin(go);
}


}*/
bool ck(){

for(int i=1;i<=n+k;i++)
        if(!vc[i])return false;
return true;

}
int main(){
   freopen("road.in","r",stdin);
     freopen("road.out","w",stdout);

scanf("%lld%lld%lld",&n,&m,&k);
for(int i=1;i<=m;i++)scanf("%lld%lld%lld",&u[i],&v[i],&w[i]);
for(int j=m+1;j<=k+m+1;j++)
    {
        scanf("%lld",&c[j]);
for(int i=1;i<=n;i++){
         scanf("%lld",&a[j][i]);
    u[i+m]=j;
    v[i+m]=i;

}}
tot=k*n+m;

int totc=n+k;


/*int st=1;
while(!ck()){
gomin(st);
st=go;


}*/

long long tmp=111100000;
for(int i=1;i<=tot;i++){

    if((u[i]==1||v[i]==1)&&(!vc[i]))
   {
       if(w[i]<tmp){
        go=i;
        tmp=w[i];


       }


   }


}
while(go<=tot&&!ck()){
    ans+=w[go];
vc[go]=1;


}
cout<<ans;




















return 0;
}
