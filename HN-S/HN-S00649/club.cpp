#include<bits/stdc++.h>
using namespace std;//remember to test
const int N=1e5;
int T,n,a,b,c,d[N+5],e[N+5],f[N+5],ans,cnt1,cnt2,cnt3;
int main(){
  freopen("club.in","r",stdin);
  freopen("club.out","w",stdout);
  ios::sync_with_stdio(false);cin.tie(0);
  cin>>T;
  while(T--){
  cin>>n;ans=cnt1=cnt2=cnt3=0;
  for(int i=1;i<=n;i++){
  cin>>a>>b>>c;
  if(a>=b&&a>=c){cnt1++;d[cnt1]=a-max(b,c);}
  else if(b>=a&&b>=c){cnt2++;e[cnt2]=b-max(a,c);}
  else {cnt3++;f[cnt3]=c-max(a,b);}
  ans+=max(a,max(b,c));
  }
  if(cnt1>n/2){
  sort(d+1,d+cnt1+1);
  for(int i=1;i<=cnt1-n/2;i++)
  ans-=d[i];
  }
  
  if(cnt2>n/2){
  sort(e+1,e+cnt2+1);
  for(int i=1;i<=cnt2-n/2;i++)
  ans-=e[i];
  }
  
  if(cnt3>n/2){
  sort(f+1,f+cnt3+1);
  for(int i=1;i<=cnt3-n/2;i++)
  ans-=f[i];
  }
  cout<<ans<<"\n";
  }
}
