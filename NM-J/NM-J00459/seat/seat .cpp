#include<bits/stdc++.h>
using namespace std;
long long m,n;
long long a[1001];
int main(){
   //freopen("seat.in","r",stdin);
  // freopen("seat.out","w",stdout);
   cin>>n>>m;
   long long num=n*m;
   cin>>a[1];
   for(long long i=2;i<=num;i++){
      cin>>a[i];
   }
   long long a1=a[1];
   sort(a+1,a+num+1);
    long long x=0;
   for(long long i=1;i<=num;i++){

       if(a[i]==a1){

        x=i;
        break;
       }

   }
   x=num-x+1;
   //cout<<x<<endl;
   long long n1,m1;
   n1=x/n;
   if(x%n==0){
        if(n1%2==0){
        m1=1;
    }
    else{
        m1=n;
    }
   }
   else{
    n1++;
    if(n1%2==0){
        m1=n-x%n+1;
    }
    else{
        m1=x%n;
    }
   }
   cout<<m1<<" "<<n1;
    return 0;
}
