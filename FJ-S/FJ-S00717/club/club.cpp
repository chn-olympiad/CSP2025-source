#include<bits/stdc++.h>
#define int long long
using namespace std;
int t,n,a[100010][5],dp[200][100][100],ans,flag1,flag2,aa[1000010],bb[1000010];
struct Edge{
	int cha,idx;
	bool operator<(const Edge x)const{
		return cha>x.cha;
	}
}v[1000010];
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","W",stdout);
	scanf("%lld",&t);
	while(t--){
		ans=0,flag1=1,flag2=1;
		scanf("%lld",&n);
		for(int i=1;i<=n;i++){
			scanf("%lld%lld%lld",&a[i][1],&a[i][2],&a[i][3]);
			aa[i]=a[i][1];
			bb[i]=a[i][2];
			v[i].cha=aa[i]-bb[i];
			v[i].idx=i;
			if(a[i][2]>0){
				flag1=0;
			}
			if(a[i][3]>0){
				flag2=0;
			}
		}
		if(flag1&&flag2&&n>200){
			sort(aa+1,aa+1+n);
			for(int i=n;i>(n>>1);i--){
				ans+=aa[i];
			}
			printf("%lld\n",ans);
			continue;
		}
		else if(flag2&&n>200){
			sort(v+1,v+1+n);
			for(int i=1;i<=(n>>1);i++){
				ans+=aa[v[i].idx];
			}
			for(int i=(n>>1)+1;i<=n;i++){
				ans+=bb[v[i].idx];
			}
			printf("%lld\n",ans);
			continue;
		}
		memset(dp,0,sizeof(dp));
		for(int i=1;i<=n;i++){
			for(int j=0;j<=(n>>1);j++){
				for(int k=0;k<=(n>>1);k++){
					if(j){
						dp[i][j][k]=max(dp[i][j][k],dp[i-1][j-1][k]+a[i][1]);
					}
					if(k){
						dp[i][j][k]=max(dp[i][j][k],dp[i-1][j][k-1]+a[i][2]);
					}
					if(i-j-k<=(n>>1)&&i-j-k>0){
						dp[i][j][k]=max(dp[i][j][k],dp[i-1][j][k]+a[i][3]);
					}
					if(i==n){
						ans=max(ans,dp[i][j][k]);
					}
//					cout<<i<<" "<<j<<" "<<k<<" "<<dp[i][j][k]<<'\n';
				}
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
