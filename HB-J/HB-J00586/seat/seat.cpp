#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int h,l;
    int a[10001] ;
    int sum = 1;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    for(int i=2;i<=n*m;i++){
        if(a[1]<a[i]){
           sum ++;
        }
    }
    if(sum%n==0){
        l=sum/n;
      if(sum%n==0){
        h =n;
      }
      else{
        h = sum%n;
      }

    }
    else{
      l=n%sum;
      if(sum%n==0){
        h = n;
      }else{
          h = sum%n;
      }
    }
    cout<<l<<" "<<h;
    return 0;
}

