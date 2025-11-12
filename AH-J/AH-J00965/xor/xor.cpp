#include <bits/stdc++.h>
using namespace std;
int n,a[100001],k,ans;
int main(){
 freopen("xor.in","r",stdin);
 freopen("xor.out","w",stdout);
 cin>>n>>k;
 for(int i=1;i<=n;i++)
  cin>>a[i];
 for(int i=1;i<=n;i++)
  for(int j=1;i+j-1<=n;j++){
   int sum=a[i];int u=i;
   while(u<=n){
    u++;
    sum=sum^a[u];
   }
   if(sum==k)ans++;
  }
 cout<<ans;
 return 0;
}
