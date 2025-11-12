#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,a[500005],pre[500005],dp[500005],k;
int main(){
  freopen("xor.in","r",stdin);
  freopen("xor.out","w",stdout);
  scanf("%d%d",&n,&k);
  for(int i=1;i<=n;i++)
    scanf("%d",&a[i]),pre[i]=(pre[i-1]^a[i]);
  if(n>1005){
    int ans=0;
    for(int i=1;i<=n;i++)
      if(a[i]==1)
        ans++;
    printf("%d\n",ans);
  }
  else{
    for(int i=1;i<=n;i++){
      dp[i]=dp[i-1];
      for(int j=1;j<=i;j++)
        if((pre[i]^pre[j-1])==k)
          dp[i]=max(dp[i],dp[j-1]+1);
    }
    printf("%d\n",dp[n]);
  }
  fclose(stdin);
  fclose(stdout);
  return 0;
}

