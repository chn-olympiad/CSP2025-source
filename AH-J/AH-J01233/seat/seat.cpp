#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL N=15;
LL n,m,a[N],p,x,y,id;
bool cmp(const LL &x,const LL &y){
  return x>y;
}
int main(){
  freopen("seat.in","r",stdin);
  freopen("seat.out","w",stdout);
  scanf("%lld %lld",&n,&m);
  for(LL i=1;i<=n*m;i++) scanf("%lld",&a[i]);
  p=a[1];
  sort(a+1,a+n*m+1,cmp);
  for(LL i=1;i<=n*m;i++)
    if(a[i]==p){
      id=i;break;
    }
  if(id<n) x=1;
  else x=id/n;
  if(id%n!=0) x++;
  y=id%n;
  if(y==0) y=n;
  if(x%2==0) y=n-y+1;
  printf("%lld %lld",x,y);
  return 0;
}
