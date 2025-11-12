#include<bits/stdc++.h>
using namespace std;
long long i,n,a[1000010],he,cnt;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(i=1;i<=n;i++){
       cin>>a[i];
    }
    if(n==3){
      he=a[1]+a[2]+a[3];
      long long mx=max(a[1],max(a[2],a[3]));
      if(he>mx*2){
        cout<<1;
      }else{
        cout<<0;
      }
    }
    if(n==4){
      long long mx[10];
      he=a[1]+a[2]+a[3]+a[4];
      long long mx[1]=max(a[2],max(a[3],a[4]));
      long long mx[2]=max(a[1],max(a[3],a[4]));
      long long mx[3]=max(a[1],max(a[2],a[4]));
      long long mx[4]=max(a[1],max(a[2],a[3]));
      long long mx[5]=max(a[1],max(a[2],max(a[3],a[4])));
      for(i=1;i<=n;i++){
         if(he-a[i]>mx[i]*2）{
           cnt++;
         }
      }
      if(he>mx[5]*2){
        cnt++;
      }
      cout<<cnt;
    }
    return 0;
}
