#include<bits/stdc++.h>
using namespace std;
int n,ans,a[5005],mod=998244353;
void dfs(int k,int sum){
if(k>n)return;
for(int i=k;i<=n;i++){
if(sum>a[i])ans=(ans+1)%mod;
sum+=a[i];
dfs(i+1,sum);
sum-=a[i];
}
}
int main(){
freopen("polygon.in","r",stdin);
freopen("polygon.out","w",stdout);
scanf("%d",&n);
for(int i=1;i<=n;i++){
scanf("%d",&a[i]);
}
sort(a+1,a+n+1);
if(n==3){
if(a[1]+a[2]>a[3])cout<<1;
else cout<<0;
}
dfs(1,0);
cout<<ans;
return 0;
}
