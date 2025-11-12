#include<bits/stdc++.h>
using namespace std;
int main(){
  freopen("seat.in","r",stdin);
  freopen("seat.out","w",stdout);
  int n,m,a[110],s,f=0;
  cin>>n>>m;cin>>s;
  for(int i=1;i<n*m;i++)cin>>a[i];
  for(int i=0;i<n*m-1;i++)if(a[i]>s)f++;
  int x,y;
  x=f/n+1;
  if(x%2==0)y=n-(f%n);
  else y=f%n+1;
  cout<<x<<" "<<y;
  return 0;
}