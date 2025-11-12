#include<bits/stdc++.h>
using namespace std;
long long i,n,k,a[10000100];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(i=1;i<=n;i++){
        cin>>a[i];
    }
    if(n<=2&&k==0){
       if（n==1){
          cout<<1;
       }else if(n==2){
           if(a[1]==a[2]){
           cout<<3;
           }else{
           cout<<2;
           }  
       }
    }
    return 0;
}
