#include<bits/stdc++.h>
using namespace std;
long long m,n,s,a[1000000],b,n1,n2;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
  cin>>n>>m;
  cin>>b;
  for(int i=1;i<=n;i++){
    cin>>a[i];
  }
  n1=1;
  n2=1;
  for(int i=1;i<=n;i++){
    n1=n1*i%998244353;
  }
  for(int i=1;i<=n-m;i++){
    n2=n2*i%998244353;
  }
  cout<<n1/n2%998244353;
  return 0;
  }
