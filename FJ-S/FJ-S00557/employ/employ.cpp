#include<bits/stdc++.h>
using namespace std;
string s;
int a[505],b[505],c[505],l,ans,mod=998244353,n,m;
void dfs(int k,int cnt,int sum){
if(k>n){
if(sum>=m)ans=(ans+1)%mod;
return;
}
for(int i=1;i<=n;i++){
if(b[i]==0){
if(a[k]==0||cnt>=c[i]){
b[i]=1;
dfs(k+1,cnt+1,sum);
b[i]=0;
}else{
b[i]=1;
dfs(k+1,cnt,sum+1);
b[i]=0;
}
}
}
}
int main(){
freopen("employ.in","r",stdin);
freopen("employ.out","w",stdout);
cin>>n>>m>>s;
for(int i=1;i<=n;i++){
cin>>c[i];
}
l=s.length();
for(int i=0;i<l;i++){
a[i+1]=s[i]-'0';
}
dfs(1,0,0);
cout<<ans;
return 0;
}
