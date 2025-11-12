#include<bits/stdc++.h> 
using namespace std;
int k,n,a[200005],ans;
int main(){
  freopen("xor.in","r",stdin);
  freopen("xor.out","w",stdout);
  cin>>n>>k;
  for(int i=1;i<=n;i++) cin>>a[i];
  if(k==0) cout<<n/2;
  else {
      for(int i=1;i<=n;i++){
      	if(a[i]!=a[i+1]&&a[i]!=2){
      		ans++;
      		a[i+1]=2;
		}
		a[i]=2;
	  }
	  cout<<ans;
  }
  return 0;
}