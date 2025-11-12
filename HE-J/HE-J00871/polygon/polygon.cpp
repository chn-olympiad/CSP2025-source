#include<bits/stdc++.h>
using namespace std;
long long ans,s;
int n,a[5005],ma;
void dfs(long long s,int ma,int b,int i,int m){
if(i>n)  return;
if(b==1){
if(a[i]>ma)  ma=a[i];
s+=a[i];
}
if(m>=3){
if(ma*2<s){
if(b==1){
ans++;
ans=ans%998244353;
}
}
}
dfs(s,ma,1,i+1,m+1);
dfs(s,ma,0,i+1,m);
}
int main(){
freopen("polygon.in","r",stdin);
freopen("polygon.out","w",stdout);
cin>>n;
for(int i=1;i<=n;i++){
cin>>a[i];
}
if(n<=20){
dfs(0,0,1,1,1);
dfs(0,0,0,1,0);
}
cout<<ans<<endl;
fclose(stdin);
fclose(stdout);
return 0;
}
