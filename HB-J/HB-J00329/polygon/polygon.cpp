#include<bits/stdc++.h>
using namespace std;
int n;
int a[5001];
//int b[5001];
long long mod=998244353;
int sum;
int m;
long long ans=0;
int q(int x,int sum,int m){
if(x==n+1){
    if(sum>m*2){
        ans++;
        ans%=mod;
     //   for(int i=1;i<=n;i++){
        //    if(b[i])  cout<<i;
       // }
      //  cout<<endl;
    }
}else{
 q(x+1,sum, m);
// b[x]++;
q(x+1,sum+a[x],max(m,a[x]));
//[x]--;
}
   }
int main(){
  freopen("polygon.in","r",stdin);
       freopen("polygon.out","w",stdout);
cin>>n;
for(int i=1;i<=n;i++){
    cin>>a[i];
}

q(1,0,0);

cout<<ans;
}
