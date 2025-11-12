#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL N=5e5+5;
struct Node{
  LL l,r;
  bool operator < (const Node &rhs){
    return r<rhs.r;
  }
}a[N];
LL n,k,x[N],maxn[N],ans=0;
bool oka=true,okb=true;
int main(){
  freopen("xor.in","r",stdin);
  freopen("xor.out","w",stdout);
  scanf("%lld %lld",&n,&k);
  x[0]=-1;
  for(LL i=1;i<=n;i++){
    scanf("%lld",&x[i]);
    if(x[i]!=1) oka=false;
    if(!(x[i]>=0&&x[i]<=1)) okb=false;
    maxn[i]=maxn[i-1]^x[i];
  }
  if(oka){
    printf("%lld",n/2);
    return 0;
  }
  if(okb){
    if(k==0){
      LL cnt=0;
      for(LL i=1;i<=n;i++){
        if(x[i]==0) cnt++;
        if(x[i]==1&&x[i-1]==1&&x[i-2]!=1) cnt++;
      }
      printf("%lld",cnt);
    }
    else{
      LL cnt=0;
      for(LL i=1;i<=n;i++)
        if(x[i]==1) cnt++;
      printf("%lld",cnt);
    }
    return 0;
  }
  for(LL len=1;len<=n;len++)
  for(LL i=1;i<=n-len+1;i++){
    LL j=i+len-1;
    if((maxn[j]^maxn[i-1])==k) {
      ans++;
      a[ans].l=i,a[ans].r=j;
    }
  }
  sort(a+1,a+ans+1);
  LL R=a[1].r,cnt=1;
  for(LL i=2;i<=ans;i++)
    if(a[i].l>R){
      cnt++;
      R=a[i].r;
    }
  printf("%lld",cnt);
  return 0;
}
