#include<bits/stdc++.h>
using namespace std;
string s[200005][5],t1,t2;
int ans,hs[200005][5],h[5][200005],p=131,mod=1e9+7,t[10]={0,1,131,17161,2248091,294499921};
int main(){
freopen("replace.in","r",stdin);
freopen("replace.out","w",stdout);
int n,q,x,y,l,r;
cin>>n>>q;
for(int i=1;i<=n;i++){
cin>>s[i][1]>>s[i][2];
x=s[i][1].length();
for(int j=x-1;j>=0;j--){
hs[i][1]=(hs[i][1]+s[i][1][j]*t[x-j]%mod)%mod;
hs[i][2]=(hs[i][2]+s[i][2][j]*t[x-j]%mod)%mod;
}
}
for(int k=1;k<=q;k++){
ans=0;
cin>>t1>>t2;
x=t1.length();
y=t2.length();
if(x!=y)ans=0;
else{
for(int i=x-1;i>=0;i--){
h[1][i+1]=(h[1][i+2]+t1[i]*t[x-i]%mod)%mod;
h[2][i+1]=(h[2][i+2]+t2[i]*t[x-i]%mod)%mod;
}
for(int i=x+1;i>=1;i--){
for(int j=1;j<=i;j++){
l=h[1][j]-h[1][i];
for(int u=1;u<=n;u++){
if(l/hs[u][1]==1||l/hs[u][1]/t[2]==1||l/hs[u][1]/t[3]==1||l/hs[u][1]/t[4]==1||l/hs[u][1]/t[5]==1){
r=h[2][j]-h[2][i];
if(r/hs[u][2]==1||r/hs[u][2]/t[2]==1||r/hs[u][2]/t[3]==1||r/hs[u][2]/t[4]==1||r/hs[u][2]/t[5]==1)ans++;
}
}
}
}
}
cout<<ans<<"\n";
}
return 0;
}
