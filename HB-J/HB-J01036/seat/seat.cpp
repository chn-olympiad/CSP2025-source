#include <bits/stdc++.h>
using namespace std;
int a[110];
int m,n;
int x,y;
int c,r;
bool cmp(int q,int p){
     return q>p;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    int k=m*n;
    for(int i=1;i<=k;i++){
       cin>>a[i];
       x=a[1]; 
    }
    sort(a+1,a+k+1,cmp);
    for(int  i=1;i<=k;i++){
        if(a[i]==x){
           y=i;
        }
    }
    if(y%n==0){
       c=y/n;
       if(c%2==0){
         r=1;
       }else{
        r=n;
       }
    }else{
     c=y/n+1;
     if(c%2==0){
       r=n-y%n+1;
       }else{
        r=y%n;
       }
    }
    cout<<c<<" "<<r;
    return 0;
}
