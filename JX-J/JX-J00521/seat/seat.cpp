#include <bits/stdc++.h>
using namespace std;
long long n,m,i,k,j,cj,wz,ls,hs,sy;
long long a[10000];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    //n infers henghangshu and m infers shulieshu
    //cj infers R's grades
    //wz infers where R's grades is
     cin>>n>>m;
     for(i=1;i<=n*m;i++){
        cin>>a[i];
     }
     cj=a[1];
     k=m*n;
     for(i=1;i<=k;i++){
        for(j=1;j<=k;j++){
            if(a[j]<a[j+1]){
                swap(a[j],a[j+1]);
            }
        }
     }
     for(i=1;i<=k;i++){
        if(cj==a[i]){
          wz=i;
        }
     }
     ls=wz/n;
     sy=wz-n*ls;
     if(sy==0){
        cout<<ls;
        if(ls%2==0){
            cout<<1<<" ";
        }
        if(ls%2==1){
            cout<<n;
        }
     }
     if(sy!=0){
        ls=ls+1;
        cout<<ls;
        if(ls%2==0){
            hs=n+1-sy;
            cout<<hs<<" ";
        }
        if(ls%2==1){
            hs=sy;
            cout<<hs;
        }
     }

    return 0;
}
