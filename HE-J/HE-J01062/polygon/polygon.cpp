#include <bits/stdc++.h>//12
using namespace std;
const int N = 5005;
int n;
int a[N];
int main(){
  freopen("polygon.in","r",stdin);
  freopen("polygon.out","w",stdout);
  cin>>n;
  int sum=0,maxx=0;
  for (int i=1; i<=n;i++){
  	cin>>a[i]; 
  	maxx=max(maxx,a[i]);
  	sum+=a[i];
  }
  if(n<3){
  	cout<<0;
  	exit(0);
  }
  if (sum>maxx*2) cout<<1;
  else cout<<0;
  return 0;
} 
