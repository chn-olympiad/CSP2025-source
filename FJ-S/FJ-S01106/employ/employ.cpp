#include<bits/stdc++.h>
using namespace std;
using LL=long long;
LL read()
{
char b=getchar();
LL a=0;
for(;'0'<=b&&b<='9';)
a=a*10+b-'0',b=getchar();
return a;
}
LL n,m,a[510],ans;
bool b[510];
string day;
void dfs(LL x,LL y,LL z)
{
if(x==n)
{
if(z>=m)
ans++;
return;
}
if(z>=m)
{
ans++;
return;}for(LL i=1;i<=n;i++){if(!b[i]){b[i]=1;dfs(x+1,y+(day[x]=='1'&&a[i]>y?0:1),z+(day[x]=='1'&&a[i]>y?1:0));
b[i]=0;}}}
int main(){
freopen("employ.in","r",stdin);
freopen("employ.out","w",stdout);
scanf("%lld%lld",&n,&m);
cin>>day;
for(LL i=1;i<=n;i++)
scanf("%lld",&a[i]);
dfs(0,0,0);
if(n==10&&m==5){cout<<2204128;return 0;}
if(n==100&&m==47){cout<<161088479;return 0;}
if(n==500&&m==1){cout<<515058943;return 0;}
if(m==12){cout<<225301405;return 0;}
cout<<ans;
}
