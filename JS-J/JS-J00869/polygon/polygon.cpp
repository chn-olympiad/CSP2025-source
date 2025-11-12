#include <bits/stdc++.h>
using namespace std;
long long a[500010],n,k,d[500010],cnt,sum;
const long long mod = 998244353;
void dfs(long long num,long long id,long long sum){
if(num>=3){
   if(sum > 2*a[id]){
    cnt=(cnt+1)%mod;
}else if(a[id+1]>=2*a[id]) return ;
}else if(n-id<3-num){
   return ;
}
for(int i=id+1;i<=n;i++){
     dfs(num+1,i,sum+a[i]);
}
}
int main(){
freopen("polygon.in","r",stdin);
freopen("polygon.out","w",stdout);
cin >> n;
for(int i=1;i<=n;i++){
    cin >> a[i];
}
sort(a+1,a+n+1);
dfs(0,0,0);
cout << cnt;
return 0;
}
