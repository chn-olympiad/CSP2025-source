#include<bits/stdc++.h>
using namespace std;
int n,m,s,num,c,r,a[120];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }s=a[1];
    sort(a+1,a+n*m+1);
    for(int i=n*m;i>=1;i--){
        if(a[i]==s){
            num=n*m-i+1;
            c=ceil(1.0*num/n);
            break;
        }
    }if(c%2){
        if(num%n){
            r=num%n;
        }else{
            r=n;
        }
    }else{
        if(num%n){
            r=n-num%n+1;
        }else{
            r=1;
        }
    }cout<<c<<' '<<r;
    return 0;
}
