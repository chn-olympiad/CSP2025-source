#include<bits/stdc++.h>
using namespace std;
int main(){
  int mc,m,n,ag=0,a[i],gdl;
  freopen("seat.in","r",stdin);
  cin>>m>>n;
  cout<<a[0];
  mc=a[0];
  for(int i=1;i<=n*m-1;i++){
    cout<<a[i];
    for(int j=0;j<=i;j++){
      if(a[i]>a[i-1]){
	gdl=a[i-1];
	a[i-1]=a[i];
	a[i]=gdl;
      }
    }
  }
  for(int i=1;i<=m;i++){
    if(i%2==1){
      for(int j=1;j<=n;j++){
	if(a[ag]==mc){
	  cout<<i<<" "<<j;
	}
	ag++;
      }
    }
    else{
      for(int j=n;j>=1;j--){
	if(a[ag]==mc){
	  cout<<i<<" "<<j;
	}
	ag++;
      }
    }
  }
  freopen("seat.out","w",stdout);
  return 0;
}