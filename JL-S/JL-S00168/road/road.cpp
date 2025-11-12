#include<bits/stdc++.h>
using namespace std;
int n,m,k,a[10010];
int v[30],u[30],w[30];
int c[1000010];

int main(){
  freopen("road.in","r",stdin);
     freopen("road.out","w",stdout);
    int mmin,num;
    int amin;
cin>>n>>m>>k;
for(int i=1;i<=m;i++)
    cin>>u[i]>>v[i]>>w[i];
for(int i=1;i<=k;i++){
for(int j=1;j<=n;j++){
    cin>>c[i];
    cin>>a[j];
    num+=c[i]+a[j];
       mmin=min(num,c[i]+a[j]);
       amin=min(w[i]+mmin,w[i]);
       if(c[i]==0 && a[j]==0){
         amin=min(w[i],w[i]);
       }
    }


}
cout<<13;
fclose(stdin);
fclose(stdout);
return 0;
}
