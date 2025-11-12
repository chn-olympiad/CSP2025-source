#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
int n,k,a[500010],s[500010],gf[500010],ans,num;
struct g2{
int x,y,w;
}g[500010];
bool cmp(g2 x,g2 y){
    return x.w<y.w;
}
signed main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
 s[i]=s[i-1] xor a[i];        
 }
 for(int i=1;i<=n;i++){
     for(int j=i;j<=n;j++){
         if((s[j] xor s[i-1])==k)g[num++]={min(i,j),max(i,j),abs(i-j)};
     }
 }
 sort(g,g+num,cmp);
 for(int i=0;i<num;i++){
     bool gfd=1;
     for(int j=g[i].x;j<=g[i].y;j++){
         if(gf[j]==1){gfd=0;break;}
     }
     if(gfd){
     ans++;
     for(int j=g[i].x;j<=g[i].y;j++){
         gf[j]=1;
     }
}
 } 
 cout<<ans;
    return 0;
}
