#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+5;
int T,n,a[N][3],cnt[3],ans;
void dfs(int sum,int t){
	if(t==n+1){
		ans=max(ans,sum);
		return ;
	}
	if(cnt[0]<n/2){
		cnt[0]++;
		dfs(sum+a[t][0],t+1);
		cnt[0]--;
	}
	if(cnt[1]<n/2){
		cnt[1]++;
		dfs(sum+a[t][1],t+1);
		cnt[1]--;
	}
	if(cnt[2]<n/2){
		cnt[2]++;
		dfs(sum+a[t][2],t+1);
		cnt[2]--;
	}
}
int vis[N],flag1,flag2;
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&T);
	while(T--){
		memset(cnt,0,sizeof(cnt));
		scanf("%lld",&n);
		for(int i=1;i<=n;i++){
			scanf("%lld%lld%lld",&a[i][0],&a[i][1],&a[i][2]);
			if(a[i][1]>0)flag1=1;
			if(a[i][2]>0)flag2=1;
		}
		if(flag1==0&&flag2==0){
			int cq[n];
			for(int i=1;i<=n;i++){
				cq[i]=a[i][0];
			}
			sort(cq+1,cq+n+1);
			for(int i=n;i>n/2;i--){
				ans+=cq[i];
			}
			printf("%lld\n",ans);
			ans=0;
			continue;
		}
		if(n<=18){
			dfs(0,1);
			printf("%lld\n",ans);
			ans=0;
		}else{
			int ans1=0,ans2=0;
			for(int i=1;i<=n;i++){
				if(a[i][0]>=a[i][1]&&a[i][0]>=a[i][2]){
					if(cnt[0]<n/2){
						cnt[0]++;
						ans1+=a[i][0];
					}else if(a[i][1]>a[i][2]){
						cnt[1]++;
						ans1+=a[i][1];
					}else {
						cnt[2]++;
						ans1+=a[i][2];
					}
				}else if(a[i][1]>=a[i][0]&&a[i][1]>=a[i][2]){
					if(cnt[1]<n/2){
						cnt[1]++;
						ans1+=a[i][1];
					}else if(a[i][0]>a[i][2]){
						cnt[0]++;
						ans1+=a[i][0];
					}else {
						cnt[2]++;
						ans1+=a[i][2];
					}
				}else if(a[i][2]>=a[i][1]&&a[i][2]>=a[i][0]){
					if(cnt[2]<n/2){
						cnt[2]++;
						ans1+=a[i][2];
					}else if(a[i][0]>a[i][1]){
						cnt[0]++;
						ans1+=a[i][0];
					}else {
						cnt[1]++;
						ans1+=a[i][1];
					}
				}
			}
			memset(cnt,0,sizeof(cnt));
			for(int i=n;i<=1;i++){
				if(a[i][0]>=a[i][1]&&a[i][0]>=a[i][2]){
					if(cnt[0]<n/2){
						cnt[0]++;
						ans2+=a[i][0];
					}else if(a[i][1]>a[i][2]){
						cnt[1]++;
						ans2+=a[i][1];
					}else {
						cnt[2]++;
						ans2+=a[i][2];
					}
				}else if(a[i][1]>=a[i][0]&&a[i][1]>=a[i][2]){
					if(cnt[1]<n/2){
						cnt[1]++;
						ans2+=a[i][1];
					}else if(a[i][0]>a[i][2]){
						cnt[0]++;
						ans2+=a[i][0];
					}else {
						cnt[2]++;
						ans2+=a[i][2];
					}
				}else if(a[i][2]>=a[i][1]&&a[i][2]>=a[i][0]){
					if(cnt[2]<n/2){
						cnt[2]++;
						ans2+=a[i][2];
					}else if(a[i][0]>a[i][1]){
						cnt[0]++;
						ans2+=a[i][0];
					}else {
						cnt[1]++;
						ans2+=a[i][1];
					}
				}
			}
			printf("%lld\n",max(ans1,ans2));
		} 
	}
	return 0;
} 
