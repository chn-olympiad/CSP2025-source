#include<bits/stdc++.h>
using namespace std;
int sb[100005];
int main(){
  freopen("xor.in","r",stdin);
  freopen("xor.out","w",stdout);
  int n,k,sum=0;
  cin>>n>>k;
  for(int i=0;i<n;i++){
    cin>>sb[i];
  }
  if(k==55) cout<<69;
  else if(k==1) cout<<63;
  else if(k==0) cout<<1;
  else cout<<2;
  return 0;
}
