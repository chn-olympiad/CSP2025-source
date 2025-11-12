#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL N=5005;
LL n,a[N],ans=0;
bool ok=true;
void dfs(LL pre,LL sum,LL maxn){
  if(sum>2*maxn){
    ans++; ans%=998244353;
  }
  for(LL i=pre+1;i<=n;i++)
    dfs(i,sum+a[i],max(maxn,a[i]));
}
int main(){
  freopen("polygon.in","r",stdin);
  freopen("polygon.out","w",stdout);
  scanf("%lld",&n);
  for(LL i=1;i<=n;i++) {
      scanf("%lld",&a[i]);
      if(a[i]!=1) ok=false;
  }
  if(ok){
    LL x=n*(n-1)%998244353;
    x=x*(n-2)%998244353;
    printf("%lld",x%998244353/6);
    return 0;
  }
  if(n==3){
    if(a[1]+a[2]+a[3]>2*max(a[1],max(a[2],a[3])))
      printf("1");
    else printf("0");
    return 0;
  }
  dfs(0,0,0);
  printf("%lld",ans%998244353);
  return 0;
}
