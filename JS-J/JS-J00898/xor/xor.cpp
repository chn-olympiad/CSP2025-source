#include<bits/stdc++.h>
using namespace std;
long long n,k,a[500010],t;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    t=1;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]!=1) t=0;
    }
    if(k==0&&t==1){
        cout<<n/2<<endl;
        return 0;
    }
    //if(k==0){
      //  for(int i=1;i<=n;i++){
            //if(a[i]==0)
     //   }
    //}
    return 0;
}
