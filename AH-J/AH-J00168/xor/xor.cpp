#include<bits/stdc++.h>
using namespace std;
long long a[500005],n,k,s[500005],dp[500005],g=0,v;
struct node{
long long l,r;	
}b[500005];
bool cmp(node A,node B){
return A.l<B.l;	
}
int main(){
ios::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);
freopen("xor.in","r",stdin);
freopen("xor.out","w",stdout);
cin>>n>>k;
for(int i=1;i<=n;i++){
cin>>a[i];	
s[i]=(s[i-1]^a[i]);
}
for(int i=1;i<=n;i++){
for(int j=1;j<=i;j++){
if((s[i]^s[j-1])==k){
node q;
q.l=j;
q.r=i;	
g++;
b[g]=q;
}
}	
}
sort(b+1,b+g+1,cmp);
if(g==0){
cout<<0;	
return 0;
}
else{
dp[1]=1;
}
for(int i=2;i<=g;i++){
v=0;
for(int j=i-1;j>=1;j--){
if(b[j].r<b[i].l){
v=j;
break;
}
}
if(v!=0)dp[i]=max(dp[v]+1,dp[v-1]+1);
else dp[i]=dp[v]+1;
}
cout<<dp[g];
return 0;
}
