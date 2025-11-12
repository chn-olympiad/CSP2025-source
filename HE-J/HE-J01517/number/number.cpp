#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("number.in","r",stdin);
freopen("number.out","w",stdout);
   long long n;
   cin>>n;
   if(n/10%10==0){
   cout<<n<<endl;
   }else if(n/10%10>=n%10){
    cout<<n/10%10<<n%10<<endl;
    }else if(n%10>=n/10%10){
   cout<<n%10<<n/10%10<<endl;
   }

    return 0;
}

