#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,a[110],xm=1;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
    cin>>a[i];
    }
    for(int i=1;i<=m*n;i++){
        if(a[1]<a[i]){
            xm++;
        }
    }
    int l,h;
    if(xm%n==0){
        l=xm/n;
    }
    else{
        l=xm/n+1;
    }
    if(l%2==0){
        if(xm%n==0){
            h=1;
        }
        else{
            h=n-(xm%n)+1;
        }
    }
    if(l%2!=0){
        if(xm%n==0){
            h=n;
        }
        else{
            h=xm%n;
        }
    }
   cout<<l<<" "<<h;
    return 0;
}
