#include<iostream>
using namespace std;
int n,k,o,ans,bu[1050000],r[600005],frt[600006];
int main(){
  freopen("xor.in","r",stdin);
  freopen("xor.out","w",stdout);
  for(int j=1;j<1050000;j++){
    bu[j]=-1;
  }
  cin>>n>>k;
  for(int j=0;j<n;j++){
    cin>>r[j];
    frt[j+1]=(frt[j]^r[j]);
  }
  for(int j=1;j<=n;j++){
    if(bu[(k^frt[j])]>=o){
        o=j;
        ans++;
    }
    bu[frt[j]]=j;
  }
  cout<<ans;
  return 0;
}
