#include<bits/stdc++.h>
using namespace std;
int main(){
 freopen("xor.in","r",stdin);
 freopen("xor.out","w",stdout);
 int n,k,a[500005]={};
 for(int i=1;i<=n;i++){
    cin>>a[i];
 }
  int b=1;
  if(a[b]>a[b+2]+a[b+3]){
    cout<<a[b];
  }else{
      if(a[b]==a[b+1]+a[b+2]){
        cout<<a[b+3];
      }else{
          cout<<a[b+1]+a[b+2];
      }
  }
 fclose(stdin);
 fclose(stdout);
 return 0;
}

