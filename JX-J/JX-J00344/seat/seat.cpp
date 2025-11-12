#include<iostream>
#include<algorithm>
using namespace std;
int a[1005];
bool cmp(int a,int b){
    return a>b;
}
int main(){
   freopen("seat.in","r",stdin);
   freopen("seat.out","w",stdout);
   int n,m;
   cin>>n>>m;
   for(int i=1;i<=n*m;i++){
       cin>>a[i];
   }
   int x=a[1];
   int s=0;
   sort(a+1,a+m*n+1,cmp);
   for(int i=1;i<=n*m;i++){
       if(a[i]==x){
          s=i;
       }
   }
   if(s%n==0){
      int a=s/n;
      if(a%2==0){
        cout<<a<<" "<<1;
      }
      else{
        cout<<a<<" "<<n;
      }
   }
   else{
      int a=s/n+1;
      int b=s%n;
      if(a%2==0){
        cout<<a<<" "<<n-b+1;
      }
      else{
        cout<<a<<" "<<b;
      }
   }
}
