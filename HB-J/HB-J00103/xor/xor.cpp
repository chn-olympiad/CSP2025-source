#include<bits/stdc++.h>
#define For(i,a,b) for(int i=a;i<=b;i++)
#define Rep(i,a,b) for(int i=a;i>=b;i--)
using namespace std;
long long n,k,cnt,ans,num,a[500005];
int main(){
   freopen("xor.in","r",stdin);
   freopen("xor.out","w",stdout);
   scanf("%lld %lld",&n,&k);
   For(i,1,n)scanf("%lld",&a[i]);
   For(i,1,n){
    cnt=a[i];
    if(cnt==k){
    ans++;
    continue;
    }
   For(j,i+1,n){
   cnt=cnt^a[j];
   if(cnt==k)ans++;
   num=j;
   }
   i=num;
   }
   printf("%lld",ans);
  return 0;
}
