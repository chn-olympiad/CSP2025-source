zha le
//#include<bits/stdc++.h>
//using namespace std;
//const int mod=998244353,N=505;
//int dp[N][N],d[N][N];
//int n,m,cnt[N],pre[N];
//char s[N];
//
//int main()
//{
//	//freopen
//	scanf("%d %d",&n,&m);
//	scanf("%s",s+1);
//	for(int i=1,c;i<=n;i++)
//	{
//		scanf("%d",&c);
//		cnt[c]++;
//	}
//	pre[0]=cnt[0];
//	for(int i=1;i<=n;i++)pre[i]=pre[i-1]+cnt[i];
//	d[0][0]=1;
//	for(int i=0;i<n;i++)
//	{
//		for(int j=0;j<=i;j++)
//		{
//			dp[j][0]=d[j][0];cerr<<i<<' '<<j<<' '<<0<<' '<<dp[j][0]<<endl;
//			d[j][0]=0;
//			for(int k=1;k<=pre[j];k++)dp[j][k]=(dp[j][k-1]+d[j][k])%mod,d[j][k]=0,cerr<<i<<' '<<j<<' '<<k<<' '<<dp[j][k]<<endl;
//		}
//		for(int j=0;j<=i;j++)
//		{
//			for(int k=0;k<=pre[j];k++)
//			{
//				if(dp[j][k]==0)continue;
//				if(s[i+1]=='0')
//				{
//					int l1=max(k,i+1+pre[j+1]-n),r1=min(i+1,min(pre[j+1],k+cnt[j+1]));
//					int l2=max(k+1,i+1+pre[j+1]-n),r2=min(i+1,min(pre[j+1],k+1+cnt[j+1]));
//					for(int ii=l1;ii<=r1;ii++)
//					{
//						d[j+1][ii]=(d[j+1][ii]+(long long)(n-i-1-ii)*dp[j][k])%mod;
//						d[j+1][ii+1]=(d[j+1][ii+1]-(long long)(n-i-1-ii)*dp[j][k]%mod+mod)%mod;
//					}
//					for(int ii=l2;ii<=r2;ii++)
//					{
//						d[j+1][ii]=(d[j+1][ii]+(long long)(pre[j+1]-ii+1)*dp[j][k])%mod;
//						d[j+1][ii+1]=(d[j+1][ii+1]-(long long)(pre[j+1]-ii+1)*dp[j][k]%mod+mod)%mod;
//					}
////					d[j+1][l1]=(d[j+1][l1]+(long long)(pre[j]-k)*dp[j][k])%mod;
////					d[j+1][r1+1]=(d[j+1][r1+1]-(long long)(pre[j]-k)*dp[j][k]%mod+mod)%mod;
////					d[j+1][l1]=(d[j+1][l1]+(long long)(cnt[j+1])*dp[j][k])%mod;
////					d[j+1][r2+1]=(d[j+1][r2+1]-(long long)(cnt[j+1])*dp[j][k]%mod+mod)%mod;
////					d[j+1][l2]=(d[j+1][l2]+(long long)(n-i-(pre[j+1]-k))*dp[j][k])%mod;
////					d[j+1][r2+1]=(d[j+1][r2+1]-(long long)(n-i-(pre[j+1]-k))*dp[j][k]%mod+mod)%mod;
//				}
//				else
//				{
//					int l1=max(k,i+1+pre[j+1]-n),r1=min(i+1,min(pre[j+1],k+cnt[j+1]));
//					d[j+1][l1]=(d[j+1][l1]+(long long)(pre[j]-k)*dp[j][k])%mod;
//					d[j+1][r1+1]=(d[j+1][r1+1]-(long long)(pre[j]-k)*dp[j][k]%mod+mod)%mod;
//					
//					d[j][k]=(d[j][k]+(long long)(n-i-(pre[j]-k))*dp[j][k])%mod;
//					d[j][k+1]=(d[j][k+1]-(long long)(n-i-(pre[j]-k))*dp[j][k]%mod+mod)%mod;
//				}
//			}
//		}
//	}
//	int ans=0;
//	for(int i=0;i<=n-m;i++)
//	{
//		for(int j=0;j<=pre[i];j++)ans=(ans+dp[i][j])%mod;
//	}
//	printf("%d",ans);
//	return 0;
//}
