#include <iostream>
using namespace std;
int main(){
   char s;
   long long int a[1000000];
   cin>>s;
   int c=0;
   for(int i=0;i<=1000000;i++){
       if(s[i]>='0'&&s[i]<='9'){
          a[i]=s[i];
          if(c<s[i]){
             c=s[i];
          }
          cout<<c;
     }

   }
   long long int b,z[1000000];
   while(c=a[1]){
       for(int i=0;i<=1000000;i++){
       if(a[i]<a[i+1]){
       b=a[i];
       a[i]=a[i+1];
       a[i+1]=b;
       z[i]=a[i];
       }
   }
       cout<<z;
   }

  return 0;
}
