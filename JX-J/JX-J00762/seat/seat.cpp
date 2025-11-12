#include<bits/stdc++.h>
using namespace std;
int a[1000],b[12][12];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
int n,m,i,j,k=0,l=1,r=1,s;
cin>>n>>m;
for(i=1;i<=n*m;i++)
cin>>a[i];
s=a[1];
sort(a+1,a+n*m+1);
for(i=n*m;i>0;i--){
    if(k==0&&l!=n){
        b[l][r]=a[i];
         l=l+1;
    }
    else if(k==0&&l==n){
        k=1;
        b[l][r]=a[i];
         r=r+1;
     }
    else if(k==1&&l!=1){
        b[l][r]=a[i];
         l=l-1;
    }
     else if(k==1&&l==1){
        k=0;
        b[l][r]=a[i];
         r=r+1;
     }
}
for(i=1;i<=m;i++){
    for(j=1;j<=n;j++){
        if(b[i][j]==s){
            cout<<j<<" "<<i;
           return 0;
       }
}

}
return 0;
}
