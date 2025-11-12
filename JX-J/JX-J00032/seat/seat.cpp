#include<bits/stdc++.h>
using namespace std;
int n,m,b=1,c=1,r=1,x;
int a[105];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    x=a[1];
    for(int i=1;i<=n*m;i++){
        if(a[i]>x){
            b++;
        }
    }
    c=(b-1)/n+1;
    if(c%2==0){
        if(b%n==0){
            r=(n-b%n+1)%n;
        }else{
            r=n-b%n+1;
        }
    }
    else{
        if(b<=n){
            r=b;
        }else if(b%n==0){
            r=n;
        }else{
            r=b%n;
        }
    }
    cout<<c<<" "<<r;
    return 0;
}
