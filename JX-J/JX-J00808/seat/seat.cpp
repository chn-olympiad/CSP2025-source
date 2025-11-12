#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("seat.in","r",stdin);
freopen("seat.out","w",stdout);
int s,n,m,s1,s2,s3;
int a[130]={};
cin>>n>>m;
for(int i=1;i<=n*m;i++){
    cin>>a[i];
}
s=a[1];
sort(a+1,a+n*m+1);
for(int i=n*m;i>=1;i--){
    if(s==a[i]){
       s1=n*m-i+1;
       break;
    }
}
if(s1<=n){
    cout<<1<<' '<<s1;
}
else{
if(s1%n==0){
     s2=s1/n;
}
else{
   s2=s1/n+1;
}
  s3=s1%n;
 if(s2%2==0){
   cout<<s2<<' ';
   if(n%2==0){
      if(s3>=n/2){
        cout<<n-s3+1;
      }
      else{
        cout<<s3+1;
      }
   }
   else{
    cout<<n-s3+1;
   }
 }
else if(s2%2!=0){
    cout<<s2<<' '<<s3;
 }

}
return 0;
}
