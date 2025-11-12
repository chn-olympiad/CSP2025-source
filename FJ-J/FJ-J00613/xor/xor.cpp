#include<bits/stdc++.h>
using namespace std;
int a[500005],x[500005],n,k,ans;
int dfs(int t,int sum){
if(t>n)return sum;
int s;
for(int i=t;i<=n;i++){
for(int j=i;j<=n;j++){
s=x[j]^x[i-1];
if(s==k){
return dfs(j+1,sum+1);
}
}
}
}
int main(){
freopen("xor.in","r",stdin);
freopen("xor.out","w",stdout);
cin>>n>>k;
for(int i=1;i<=n;i++){
cin>>a[i];
if(i>1)x[i]=x[i-1]^a[i];
else x[i]=a[i];
}
ans=dfs(1,0);
cout<<ans;
return 0;
}
