#include<bits/stdc++.h>
using namespace std;
const int N=5*1e5;
int a[N];
int q[N];
int main(){
   freopen("xor.in","r",stdin);
   freopen("xor.out","w",stdout);
    int n,k;
    cin >>n >> k;
    int ans=0;
    for(int i=1;i<=n;i++){
    cin >>a[i];
    q[i]=a[i]^q[i-1];
    }
    for(int i=1;i<=n;i++){
      if(a[i]==k){
        ans++;
        continue;
      }
      for(int j=i+1;j<=n;j++){
      if(q[j]^a[i-1]==k){
      ans++;
      i=j;
      break;
      }
      }
    }
    cout <<ans;
    return 0;
}
