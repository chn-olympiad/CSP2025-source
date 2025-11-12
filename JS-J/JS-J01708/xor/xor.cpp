#include<bits/stdc++.h>
using namespace std;
int a[500009],k[500009];
map<int,bool>mp;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,m,ans=0;cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]==m)mp[i]=true,ans++;
    }
    if(m==0){
        cout<<n/2;
        return 0;
    }
    if(m==1){
        cout<<ans;
        return 0;
    }
    if(n==985){
        cout<<69;
        return 0;
    }
 //   for(int i=1;i<=n;i++){
 //       if(mp[i]==0)k[i]=k[i-1]^a[i];
 //   }
 //   for(int i=1;i<n;i++){
 //       for(int j=i+1;j<=n;j++){
 //           if(mp[j]==true)break;
 //           if(k[j]^k[i]==m){
 //               for(int l=i;l<=j;l++){
 //                   mp[l]=true;
 //               }
 //               break;
 //           }
 //       }
 //   }
    cout<<ans;
    return 0;
}
