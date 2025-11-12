#include<iostream>
using namespace std;

int main(){
   // freopen("seat.in","r",stdin);
    //freopen("seat.out","w",stdout);
    int n,m,s=1,b,h,l;
    int a[1000005];
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
        b=a[1];
    }
    for(int i=1;i<=n*m;i++){
        if(b<a[i]){
           s++;
        }
    }
    if(s%n==0){
        l=s/n;
    }
    else{
        l=s/n+1;
    }
    if(l%2!=0){
      if(s%2==0&&s%n!=0){
        h=s%n;
      }
      else if(s%2==0&&s%n==0){
        h=n;
      }
      else{
        h=s%n;
      }
    }
    else{
        if(s%2==0&&s%n!=0){
            h=n-s%n+1;
        }
        else if(s%2==0&&s%n==0){
            h=1;
        }
        else{
            h=n-s%n+1;
        }
    }
    cout<<l<<' '<<h;
    return 0;
}
