#include<bits/stdc++.h>
using namespace std;
int n,m,h,x,y;
int a[105];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    h=a[1];
    sort(a+1,a+n*m+1);
    for(int i=1;i<=n*m;i++){
        if(a[i]==h){
            h=n*m-i+1;
        }
    }
    if(h%n==0)y=h/n;
    else y=h/n+1;
    if(h%n==0){
        if(y%2==1){
            x=n;
        }else{
            x=1;
        }
    }else{
        if(y%2==1){
            x=0+h%n;
        }else{
            x=n-h%n+1;
        }
    }
    cout<<y<<" "<<x;
    return 0;
}
