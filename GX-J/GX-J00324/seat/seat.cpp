#include<bits/stdc++.h>
using namespace std;
int main(){
  freopen("seat.in","r",stdin);
  freopen("seat.out","w",stdout);
  short m,n,a[100],p[100],c,r,w,d,xr,b;
  cin>>n>>m;
  for(int i=0;i<m*n;i++){
    cin>>a[i];
  }
  xr = a[0];
  for(int i=0;i<m*n;i++){
    p[i]=0;
    for(int j=0;j<m*n;j++){
      if(a[j]>p[i]){
        p[i]=a[j];
        b=j;
      }
    }a[b]=0;
  }
  for(int i=0;i<m*n;i++){
      if(p[i]==xr){
        w=i;
      }
  }
  c = (w/n)+1;
  d = w%n;
  if(c%2==0){
    r = n-d;
  }else{
    r = d+1;
  }
  cout<<c<<" "<<r;
  return 0;
}
