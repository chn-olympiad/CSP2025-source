#include<bits/stdc++.h>
using namespace std;
int main(){
   freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
   string a;
   cin>>a;
   long long b=a.length();
   long long d[b]={0};
   long long k=0;
   for(int i=0;i<b;i++){
    if(a[i]<='9'){
        d[k]=a[i]-48;
        k++;
    }
   }
   int max1=0,max2;
   for(int i=0;i<k;i++){
   for(int j=0;j<k;j++){
        if(max1<=d[j]){
            max1=d[j];
            max2=j;
        }
   }
         d[max2]=0;
      cout<<max1;
      max1=0;
   }
   return 0;
}
