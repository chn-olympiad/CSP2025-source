#include<bits/stdc++.h>
using namespace std;
long long cnt;
int f;
int a[5005];
int main(){
 freopen("polygon.in","r",stdin);
 freopen("polygon.out","w",stdout);
 int n;
 cin>>n;
 for(int i=1;i<=n;i++){
  cin>>a[i];
 }
 sort(a+1,a+n+1);
 if(a[n]==1){
 	for(int i=1;i<=n-2;i++){
  cnt+=i*(n-1-i);
 }
  cout<<cnt%998244353;
 }
 else{
  if(n==3&&a[1]+a[2]>a[3]) cout<<"1";
 }
 return 0;
}