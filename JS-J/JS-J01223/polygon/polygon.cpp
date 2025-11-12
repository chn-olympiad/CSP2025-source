#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,a[5005];
ll tri[5005][5005];
const int mod=998244353;
ll ans;
int main(){
  freopen("polygon.in","r",stdin);
  freopen("polygon.out","w",stdout);
  scanf("%d",&n);
  for(int i=0;i<n;i++)
    scanf("%d",&a[i]);
  if(n>50){
    tri[1][0]=tri[1][1]=1;
    for(int i=2;i<=n;i++){
      tri[i][0]=1;
      for(int j=1;j<=i;j++)
        tri[i][j]=tri[i-1][j-1]+tri[i-1][j],tri[i][j]%=mod;
    }
    for(int i=3;i<=n;i++)
      ans+=tri[n][i],ans%=mod;
    printf("%lld\n",ans);
  }
  else{
    for(int i=1;i<(1<<n);i++){
      bool cho[25];
      int sum=0,maxn=0,rp=0;
      for(int j=0;j<n;j++){
        cho[j]=i&(1<<j);
        if(cho[j])
          rp++,sum+=a[j],maxn=max(maxn,a[j]);
      }
      if(sum>2*maxn&&rp>=3)
        ans++,ans%=mod;
    }
    printf("%lld\n",ans);
  }
  fclose(stdin);
  fclose(stdout);
  return 0;
}


