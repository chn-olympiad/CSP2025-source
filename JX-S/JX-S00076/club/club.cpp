#include<bits/stdc++.h>
using namespace std;
#define Open(x) FILE *filein=freopen(#x".in","r",stdin),*fileout=freopen(#x".out","w",stdout);
#define int long long
const signed N=200005;
int T,n,a[N],b[N],c[N],mx[N],mi[N],val[N],op[N],ans,tot,t[N];
signed main(){
  Open(club);
  ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
  cin>>T;
  while(T--){
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i]>>b[i]>>c[i],mx[i]=max(a[i],max(b[i],c[i])),mi[i]=min(a[i],min(b[i],c[i])),val[i]=a[i]+b[i]+c[i]-mx[i]-mi[i],val[i]=mx[i]-val[i];
    int sa=0,sb=0,sc=0;tot=ans=0;
    for(int i=1;i<=n;i++){
      if(mx[i]==a[i])sa++,op[i]=1;
      else if(mx[i]==b[i])sb++,op[i]=2;
      else sc++,op[i]=3;
      ans+=mx[i];
    }
    if(max(sa,max(sb,sc))<=n/2){cout<<ans<<'\n';continue;}
    for(int i=1;i<=n;i++){
      if(sa>n/2&&op[i]==1)t[++tot]=val[i];
      if(sb>n/2&&op[i]==2)t[++tot]=val[i];
      if(sc>n/2&&op[i]==3)t[++tot]=val[i];
    }
    sort(t+1,t+tot+1);
    for(int i=1;i<=max(sa,max(sb,sc))-n/2;i++)ans-=t[i];
    cout<<ans<<'\n';
  }
  return 0;
}
