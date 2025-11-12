#include<bits/stdc++.h>
using namespace std;
int n,m,a[105];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","W",stdout);
    cin>>n>>m;
    for(int i=0;i<n*m;i++){
    cin>>a[i];
    }
    int x=a[0];
    sort(a,a+n*m);
    int k;
    for(int i=0;i<n*m;i++){
    if(x==a[i]){
    k=n*m-i;
    break;
    }
    }
    int c=(k-1)/n+1,r=k%n;
    if(r==0){
        r=n;
    }
    if(c%2==0){
    cout<<c<<" "<<n-r+1;
    }
    else{
    cout<<c<<" "<<r;
    }
return 0;
}
