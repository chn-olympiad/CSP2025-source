#include<bits/stdc++.h>
using namespace std;
int P=998244353;
int n,m;
string S;
int num[505],pre[505];
int dp[505][505][505];
int fac[505];
int invfac[505];
int power(int x,int y=P-2){
   if(!y)return 1;
   int tmp=power(x,y>>1);
   if(y&1)return 1ll*tmp*tmp%P*x%P;
   return 1ll*tmp*tmp%P;
}
int C(int x,int y){
   return 1ll*fac[x]*invfac[y]%P*invfac[x-y]%P;
}
int val[505][505];
int main(){
   freopen("employ.in","r",stdin);
   freopen("employ.out","w",stdout);
   fac[0]=1;
   for(int i=1;i<=500;i++){
      fac[i]=1ll*fac[i-1]*i%P;
   }
   invfac[500]=power(fac[500]);
   for(int i=500;i>=1;i--){
      invfac[i-1]=1ll*invfac[i]*i%P;
   }
   scanf("%d%d",&n,&m);
   cin>>S;
   S='?'+S;
   for(int i=1;i<=n;i++){
      int x;
      scanf("%d",&x);
      num[x]++;
   }
   for(int i=0;i<=n;i++)pre[i]=num[i];
   for(int i=1;i<=n;i++)pre[i]+=pre[i-1];
   dp[0][0][0]=1;
   for(int i=1;i<=n;i++){//考虑到最后的时候废弃点一定没有了。
      if(S[i]=='1'){//第i天可能成功。
         for(int j=0;j<=i&&j+m<=n;j++){
            for(int l=0;l<=min(i,n-pre[j]);l++){
               //如果真的成功，那就认为是一次随机
               dp[i][j][l+1]+=dp[i-1][j][l];
               if(dp[i][j][l+1]>=P)dp[i][j][l+1]-=P;
               
               int A=(i-1-l);//前面用了A次不可成功的点
               int B=pre[j];//前面有B个不可成功的点
               int D=B-A;//前面有D个不可成功的点可以用
               for(int m=0;m<=min(num[j+1],l);m++){//前面有m个点随到了j+1
                  dp[i][j+1][l-m]+=1ll*
                  dp[i-1][j][l]*
                  C(l,m)%P
                  *fac[num[j+1]]%P*invfac[num[j+1]-m]%P
                  *D%P;
                  if(dp[i][j+1][l-m]>=P)dp[i][j+1][l-m]-=P;
               }
            }
         }
      }
      else{//第i天一定失败
         for(int j=0;j<=i&&j+m<=n;j++){
            for(int l=0;l<=min(i,n-pre[j]);l++){
               if(!dp[i-1][j][l])continue;
               int D=pre[j]-i+l+1;//前面有D个不可成功的点可以用
               // printf("i=%d j=%d l=%d D=%d\n",i,j,l,D);
               for(int m=0;m<=min(num[j+1],l);m++){//前面有m个点随到了j+1
                  dp[i][j+1][l-m]+=1ll*
                  dp[i-1][j][l]*
                  C(l,m)%P
                  *fac[num[j+1]]%P*invfac[num[j+1]-m]%P
                  *D%P;
                  if(dp[i][j+1][l-m]>=P)dp[i][j+1][l-m]-=P;
                  //如果使用可成功的，则认为是一次随机
               }
               for(int m=0;m<=min(num[j+1],l+1);m++){//前面有m个点随到了j+1
                  // printf("m=%d C=%d %lld\n",m,C(l+1,m),1ll*fac[num[j+1]]%P*invfac[num[j+1]-m]%P);
                  dp[i][j+1][l+1-m]+=1ll*
                  dp[i-1][j][l]*
                  C(l+1,m)%P
                  *fac[num[j+1]]%P*invfac[num[j+1]-m]%P;
                  if(dp[i][j+1][l+1-m]>=P)dp[i][j+1][l+1-m]-=P;
                  //认为是一次随机。
               }
            }
         }
      }
      // for(int j=0;j+m<=n;j++){
      //    for(int l=0;l<=n;l++){
      //       printf("i=%d j=%d l=%d dp=%d\n",i,j,l,dp[i][j][l]);
      //       // ans+=1ll*dp[n][j][l]*fac[l]%P;
      //       // if(ans>=P)ans-=P;
      //    }
      // }
   }
   int ans=0;
   for(int j=0;j+m<=n;j++){
      for(int l=0;l<=n-pre[j];l++){
         //pre[j]+l<=n
         int A=(n-l);//前面用了A次不可成功的点
         int B=pre[j];//前面有B个不可成功的点
         int D=B-A;//前面有D个不可成功的点可以用
         if(D>0)continue;
         // printf("j=%d l=%d dp=%d\n",j,l,dp[n][j][l]);
         ans+=1ll*dp[n][j][l]*fac[l]%P;
         if(ans>=P)ans-=P;
      }
   }
   printf("%d\n",ans);
   return 0;
}
/*
1. 设dp[i][j][l]表示前i天有j次失败其中l次在可能成功的点里随机

考虑l表示还可能成功的点用了多少次，那么i-l就是不可能成功的点用了多少次，由此可以计算还剩下多少不可能成功的点。

第i天成功
dp[i][j][l] -> dp[i+1][j][l+1]
第i天的人放弃
dp[i][j][l]*C(l,m)*((num[j+1]!)/(m!)) -> dp[i+1][j+1][l-m]
*/