#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,b,c,r;
    b=n*m;
    int a[b],g=1;
    cin>>n>>m;
    for(int i=1;i<=b;i++){
    cin>>a[i];
    }
    for(int i=1;i<=b;i++){
       if(a[1]<a[i]){
       g++;
       }
    }
    if(g%n==0){
    c=g/n;
    }else{
    c=g/n+1;
    }
    if(c%2==0){
    r=n-g%n+1;
    }else{
    r=g%n;
    }
    cout<<c<<" "<<r<<endl;
}
