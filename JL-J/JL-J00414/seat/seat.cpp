#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.out","w",stdout);
    freopen("seat.in","r",stdin);
    int m,n,h,s=1,x,y;
    cin>>n>>m;
    int a[m*n+1];
    for(int i=1;i<=m*n;i++){
        cin>>a[i];
    }
    h=a[1];
    for(int i=n*m;i>=1;i--){
        if(h>a[i]){
            s++;
        }
    }
    s--;
    s=m*n-s;

    if(s%n==0){
        y=s/n;
    }else{
        y=s/n+1;
    }
    if(y%2==0){
        x=n+1-s%n;
    }else{
        if(s%n==0){
            x=s;
        }else{
            x=s%n;
        }
    }
    cout<<y<<" "<<x;
    return 0;
}
