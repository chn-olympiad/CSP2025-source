#include<bits/stdc++.h>
using namespace std;
long long cnt,ok2,t,n,a[100005][5],l,ans,minn,dp[105][105][105],ok1,b[100005],vis[100005];
struct ll{
	long long x,id;
}s[1000005];
bool camp(ll A,ll B){
	return A.x>B.x; 
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&t);
	while(t--){
		ans=0;
		scanf("%lld",&n);
		for(long long i=1;i<=n;i++){
			scanf("%lld%lld%lld",&a[i][1],&a[i][2],&a[i][3]);
			if(a[i][2] or a[i][3])ok1=1;
			if(a[i][3])ok2=1;
		}
		if(n<=200){
			memset(dp,0,sizeof(dp));
			for(long long i=1;i<=n;i++){
				for(long long j=0;j<=n/2;j++){
					for(long long k=0;k<=n/2;k++){
						if(j+k>i)continue;
						l=i-j-k;
						if(l>n/2)continue;
						if(j>0)dp[j][k][l]=max(dp[j][k][l],dp[j-1][k][l]+a[i][1]);
						if(k>0)dp[j][k][l]=max(dp[j][k-1][l]+a[i][2],dp[j][k][l]);
						if(l>0)dp[j][k][l]=max(dp[j][k][l],dp[j][k][l-1]+a[i][3]);
				//		if(dp[j][k][l])cout<<j<<' '<<k<<' '<<l<<' '<<dp[j][k][l]<<endl;
						ans=max(ans,dp[j][k][l]);
					}
				}
			}
			printf("%lld\n",ans);
		}else if(!ok1){
			for(long long i=1;i<=n;i++)b[i]=a[i][1];
			sort(b+1,b+1+n);
			for(long long i=n;i>=n/2+1;i++)ans+=b[i];
			printf("%lld\n",ans);
		}else if(!ok2){
			long long shu=0,shu1=0,shu2=0;
			for(long long i=1;i<=n;i++){
				shu=min(a[i][1],a[i][2]);
				ans+=shu;
				a[i][1]-=shu;
				a[i][2]-=shu; 
				s[++cnt].x=a[i][1];
				s[cnt].id=1;
				s[++cnt].x=a[i][2];
				s[cnt].id=2;
			}
			sort(s+1,s+1+n,camp);
			long long now;
			for(long long i=1;i<=n;i++){
				if(vis[s[i].id])continue;
				vis[s[i].id]=1;
				ans+=s[i].x;
				if(s[i].id==1)shu1++;
				else shu2++;
				if(shu1==n/2 or shu2==n/2){
					now=i+1;
					break;
				}
			}
			for(long long i=now;i<=n;i++){
				if(vis[s[i].id])continue;
				if(shu1==n/2 and s[i].id==2){
					ans+=s[i].x;
					vis[s[i].id]=1;
				}else if(shu2==n/2 and s[i].id==1){
					ans+=s[i].x;
					vis[s[i].id]=1;
				}
			}
			printf("%lld\n",ans);
			memset(vis,0,sizeof(vis));
			ans=0;
			cnt=0;
		}
	}
	return 0;
} 
