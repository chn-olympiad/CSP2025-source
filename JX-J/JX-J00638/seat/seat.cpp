#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("seat.in","r",stdin);
freopen("seat.out","w",stdout);
    int n,m;
    int c=1,r=1;
    int y;
    int a[10005];
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
       cin>>a[i];
       if(i==1){
        y=a[i];
       }
       if(c%2!=0){
        if(y<a[i]){
            r=r+1;
        }
        if(r>m){
            c=c+1;
            r=m;
        }
       }else{
           if(y<a[i]){
            r=r-1;
           }
           if(r<1){
            c=c+1;
            r=1;
           }
       }
    }
    cout<<c<<" "<<r;
 return 0;
 }
