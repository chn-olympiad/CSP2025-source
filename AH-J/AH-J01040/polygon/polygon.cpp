#include<bits/stdc++.h>
using namespace std;
long long n,a[111111],k,cnt,vis[111111],ans;
int chen(long long x){
    long long ji=1;
   for(int i=1;i<=x;i++){
    ji*=i;
    ji%=998244353;
   }
   return ji;
}
int dfs(long long maxn,long long he,long long cen){
    if(cen==k){
        if(maxn*2<he){
            cnt++;
        }
        return 0;
    }
  for(int i=1;i<=n;i++){
    if(!vis[i]){
    vis[i]++;
    dfs(max(maxn,a[i]),he+a[i],cen+1);
    vis[i]--;
    }
  }
  return 0;
}
int main(){
freopen("polygon.in","r",stdin);
freopen("polygon.out","w",stdout);
cin>>n;
for(int i=1;i<=n;i++){
    cin>>a[i];
}
for(k=3;k<=n;k++){
    dfs(0,0,0);
ans+=cnt/chen(k);
cnt=0;
}
cout<<ans;
return 0;
}

