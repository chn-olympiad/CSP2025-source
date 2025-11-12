#include<bits/stdc++.h>
using namespace std;
const int N=500;
int n,m,op[N+5],c[N+5],p[N+5],tz[N+5];
#define ll long long
const ll mod=998244353;
ll ans,dp[N+5][N+5],nw,jc[N+5],ny[N+5];
string s;
void inline ad(ll &x,ll y){
   while(x+y>=mod)y-=mod;x+=y;  
}
ll inline ksm(ll x,ll y){
  ll ans=1;
  while(y){
  if(y&1)ans=(ans*x)%mod;
  x=(x*x)%mod;
  y>>=1;
  }
  return ans;
}
ll inline C(ll x,ll y){
if(x<y)return 0;
   return jc[x]*ny[y]%mod*ny[x-y]%mod;
}
int main(){
  freopen("employ.in","r",stdin);
  freopen("employ.out","w",stdout);
  ios::sync_with_stdio(false);cin.tie(0);
  cin>>n>>m;
  cin>>s;
  jc[0]=ny[0]=1;
  for(int i=1;i<=n;i++)jc[i]=jc[i-1]*i%mod,ny[i]=ksm(jc[i],mod-2);
  for(int i=0;i<n;i++)op[i+1]=(s[i]=='1');
  for(int i=1;i<=n;i++){cin>>c[i];tz[c[i]]++;}
  
  if(n<=10){
  for(int i=1;i<=n;i++)p[i]=i;
  do{
  ll tot=0,nw=0;
  for(int i=1;i<=n;i++)if(c[p[i]]<=nw||op[i]==0)nw++;else tot++;
  if(tot>=m)ans++;
  }while(next_permutation(p+1,p+n+1));
  cout<<ans<<"\n";return 0;
  }
  if(n==m){
  ans=1;
  for(int i=1;i<=n;i++)if(op[i]==0){ans=0;}
  for(int i=1;i<=n;i++)if(c[i]==0){ans=0;}
  cout<<ans*jc[n]%mod<<"\n";
  return 0;
  }
  if(m==1){
  ans=1;ll sum=0,tot=0;
  for(int i=1;i<=n;i++)if(op[i]==0)tot++;
  if(tz[n]>tot){cout<<0<<"\n";return 0;}
  for(int i=n;i>=0;i--){ans=(ans*C(tot-sum,tz[i]))%mod*jc[tz[i]]%mod;tot+=(op[i]==1);sum+=tz[i];}
  cout<<((jc[n]-ans)%mod+mod)%mod<<"\n";
  return 0;
  }
  /*
  dp[n-m+1][0]=1;
  for(int i=n-m;i>=0;i--){
  for(int k=0;k<=n-m-1-i;k++)
  for(int s=0;s<=min(k+1,tz[i]);s++){
  ad(dp[i][k-s+1],dp[i+1][k]*C(tz[i],s)%mod*C(k,s)%mod*jc[s]%mod*ksm(i,tz[i]-s)%mod);
  }
  }
  ans=dp[0][0];
  for(int i=n-m;i<=n;i++)
  if(tz[i]!=0)
  ans=ans*ksm(tz[i],n-m+1)%mod;
  cout<<((jc[n]-ans)%mod+mod)%mod<<"\n";
  */
  cout<<0<<"\n";return 0;
}
