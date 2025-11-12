#include<bits/stdc++.h>
using namespace std;
const int MAXN=200010;
int t,n,a[MAXN][3],dp[MAXN][3],cnt[3];//0-1,1-2,2-3
map<int,int>Map;
int compare(int x,int y,int z){
	if(x>=y&&y>=z&&cnt[0]<n){
		return x;
		cnt[0]++;
	}else{
		if(y>=x&&y>=z&&cnt[1]<n){
			return y;
			cnt[1]++;
		}else{
			return z;
			cnt[2]++;
		}
	}
}
bool fa(int n){
	for(int i=1;i<=n;i++){
		if(a[i][1]!=0||a[i][2]!=0)
			return false;
	}
	return true;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	int ord[MAXN];
	while(t--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			for(int j=0;j<3;j++)
				scanf("%d",&a[i][j]);
		memset(cnt,0,sizeof(cnt));
		if(n==2){
			printf("%d\n",compare(max((a[1][0]+a[2][1]),(a[1][0]+a[2][2])),max((a[1][1]+a[2][0]),(a[1][1]+a[2][2])),max((a[1][2]+a[2][0]),(a[1][2]+a[2][1]))));
			for(int i=1;i<=2;i++)
				for(int j=0;j<3;j++)
					a[i][j]=0;
		}else{
			if(n==4){
				int w=0;
				for(int i=0;i<3;i++){
					cnt[i]++;
					for(int j=0;j<3;j++){
						cnt[j]++;
						if(cnt[j]==2){
							cnt[j]--;
							continue;
						}
						for(int k=0;k<3;k++){
							cnt[k]++;
							if(cnt[k]==2){
								cnt[k]--;
								continue;
							}
							for(int l=0;l<3;l++){
								cnt[l]++;
								if(cnt[l]==2)
									cnt[l]--;
									continue;
								w=max(w,(a[1][i]+a[2][j]+a[3][k]+a[4][l]));
							}
						}
					}
				}
				printf("%d\n",w);
			}else{
				if(fa(n)){
					memset(ord,0,sizeof(ord));
					int ans=0;
					for(int i=1;i<=n;i++){
						ord[i]=a[i][0];
					}
					sort(ord+1,ord+n+1);
					for(int i=n;i>=n/2+1;i--){
						ans+=ord[i];
					}
					printf("%d\n",ans);
				}
			}
		}
		if(n==2||n==4||fa(n))
			continue;
		else{
			dp[1][0]=a[1][0];
			dp[1][1]=a[1][1];
			dp[1][2]=a[1][2];
			memset(cnt,0,sizeof(cnt));
			for(int i=2;i<=n;i++){
				for(int j=0;j<3;j++){
					dp[i][j]=compare(dp[i-1][0],dp[i-1][1],dp[i-1][2])+a[i][j];
				}
			}
			printf("%d\n",compare(dp[n][0],dp[n][1],dp[n][2]));
			for(int i=1;i<=n;i++){
				for(int j=0;j<3;j++){
					a[i][j]=0;
					dp[i][j]=0;
				}
			} 
		}
	}
	return 0;
}
