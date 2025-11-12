#include<bits/stdc++.h>
#define For(i,a,b) for(int i=a;i<=b;i++)
#define Rep(i,a,b) for(int i=a;i>=b;i--)
using namespace std;
long long n,m,x,b,c,num,ans,a[105];
int main(){
  freopen("seat.in","r",stdin);
  freopen("seat.out","w",stdout);
  scanf("%lld %lld",&n,&m);
  x=n*m;
  For(i,1,x)scanf("%lld",&a[i]);
  num=a[1];
  sort(a+1,a+1+x);
  Rep(i,x,1)if(a[i]==num){
  ans=x-i+1;
  break;
  }
  b=ans/n;
  c=ans%n;
  if(c==0&&b%2==1)printf("%lld %lld",b,n);
  else if(c==0&&b%2==0)printf("%lld 1",b);
  else if((b+1)%2==1)printf("%lld %lld",b+1,c);
  else if((b+1)%2==0)printf("%lld %lld",b+1,n-c+1);
  return 0;
}
