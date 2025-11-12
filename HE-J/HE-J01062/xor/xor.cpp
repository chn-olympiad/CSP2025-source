#include <bits/stdc++.h>//25
using namespace std;
const int N = 5e5+5;
int a[N];
int main(){
  freopen("xor.in","r",stdin);
  freopen("xor.out","w",stdout);
  int n,k;
  cin>>n>>k;
  for (int i=1; i<=n;i++){
  	cin>>a[i];
  }
  int cnt=0;
  if (k>1){
  	for (int i=1; i<=n;i++){
  	  if (a[i]==k){
  	    cnt++;
	  }
	}
	cout<<cnt;
	exit(0);
  }
  if(k==0){
  	for (int i=1; i<=n;i++){
  	  if (a[i]==0) cnt++;
  	  if (a[i]==1&&a[i+1]==1){
  	  	i++;
  	  	cnt++;
	  }
	}
	exit(0);
  }
  if(k==1){
  	for (int i=1; i<=n;i++){
  	  if (a[i]==1) cnt++;
	}
	cout<<cnt;
	exit(0);
  }
  return 0;
}
