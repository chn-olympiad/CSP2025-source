#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("employ.in","r",stdin);
freopen("employ.out","w",stdout);
  int n,m;
  cin>>n>>m;
  long long len;
  long long c[505];
  cin>>len;
  for(int i=1;i<=n;i++){
    cin>>c[i];
  }
  long long emple=0;
  while(len>=0){
    emple+=len%10;
    len=len/10;
  }
  if(len==m) cout<<len*(len-1)%998%244%353;
  else cout<<(len-m)*(len-m-1)*len*(len-1)%998%244%353;
return 0;
}
