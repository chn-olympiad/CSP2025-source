#include<bits/stdc++.h>
using namespace std;
    int n,m,x,z,c,r;
    int a[105],b[105];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n*m;i++){
        cin>>a[i];
    }
    x=a[0];
    sort(a,a+n*m);
    for(int i=0;i<n*m;i++){
        b[i]=a[n*m-i-1];
    }
    for(int i=0;i<n*m;i++){
        if(b[i]=x){
            z=i+1;
        }
    }
    if(z%n==0){
        c=z/n;
    }
    else{
        c=z/n+1;
    }
    if(z<=n){
        cout<<1<<" "<<z;
    }
    else if(c%2==1){
        r=z%n;
        cout<<c<<" "<<r;
    }
    else if(c%2==0){
        r=n-z%n+1;
        cout<<c<<" "<<r;
    }

    return 0;
}
