//GZ-S00418 贵阳市第十八中学 谷佳鸿
#include<bits/stdc++.h>
using namespace std;
//#define int long long
//#define pii pair<int,int>
const int maxn=1e5+5;
int n,a[maxn][5],T,dp[205][205][205],cnt[5],cha[maxn],ans,tot;
struct node{
	int x,y,z;
	int max1,mid,min1;
	int maxid,midid,minid;
}sat[maxn];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		cnt[1]=cnt[2]=cnt[3]=0;
		ans=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				scanf("%d",&a[i][j]);
			}sat[i].x=a[i][1];
			sat[i].y=a[i][2];
			sat[i].z=a[i][3];
			sat[i].max1=max({sat[i].x,sat[i].y,sat[i].z});
			sat[i].min1=min({sat[i].x,sat[i].y,sat[i].z});
			if((a[i][1]>=a[i][2]&&a[i][1]<=a[i][3])||(a[i][1]<=a[i][2]&&a[i][1]>=a[i][3]))sat[i].mid=a[i][1];
			if((a[i][2]>=a[i][1]&&a[i][2]<=a[i][3])||(a[i][2]<=a[i][1]&&a[i][2]>=a[i][3]))sat[i].mid=a[i][2];
			if((a[i][3]>=a[i][1]&&a[i][3]<=a[i][2])||(a[i][3]<=a[i][1]&&a[i][3]>=a[i][2]))sat[i].mid=a[i][3];
			
			if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3])sat[i].maxid=1;
			if(a[i][2]>=a[i][1]&&a[i][2]>=a[i][3])sat[i].maxid=2;
			if(a[i][3]>=a[i][1]&&a[i][3]>=a[i][2])sat[i].maxid=3;
			
			if(a[i][1]<=a[i][2]&&a[i][1]<=a[i][3])sat[i].minid=1;
			if(a[i][2]<=a[i][1]&&a[i][2]<=a[i][3])sat[i].minid=2;
			if(a[i][3]<=a[i][1]&&a[i][3]<=a[i][2])sat[i].minid=3;
			sat[i].midid=6-sat[i].minid-sat[i].maxid;
		}
		if(n<=200){
			for(int i=1;i<=n;i++){
				for(int j=0;j<=i;j++){
					for(int k=0;k+j<=i;k++){
						int tmp=0;
						if(j)tmp=max(tmp,dp[i-1][j-1][k]+a[i][2]);
						if(k)tmp=max(tmp,dp[i-1][j][k-1]+a[i][3]);
						if(j+k<i)tmp=max(tmp,dp[i-1][j][k]+a[i][1]);
						dp[i][j][k]=tmp;
						if(i==n&&j<=n/2&&k<=n/2&&j+k>=n/2)ans=max(ans,dp[i][j][k]);
					}
				}
			}printf("%d\n",ans);
			continue;
		}
		tot=0;
		for(int i=1;i<=n;i++){
		//加入max
			ans+=sat[i].max1;
			cnt[sat[i].maxid]++;
		}int maxcnt=max({cnt[1],cnt[2],cnt[3]});
		//计算差值
		for(int i=1;i<=n;i++){
			if(cnt[sat[i].maxid]==maxcnt)
				cha[++tot]=sat[i].max1-sat[i].mid;
//			printf("%d %d %d %d\n",sat[i].max1,sat[i].maxid,sat[i].mid,cha[i]);
		}
		//统计答案 
		sort(cha+1,cha+tot+1);
		if(maxcnt>n/2){ 
			for(int i=1;i<=maxcnt-n/2;i++){
				ans-=cha[i];
			}
		}printf("%d\n",ans);
	}
	return 0;
}


