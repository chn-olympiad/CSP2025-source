#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN=1e5+5;
int t,n;
struct node{
	int x,id;
}a[MAXN][5];
bool cmp(node x,node y){
	return x.x>y.x;
}
int ans;
void dfs(int k,int cnt1,int cnt2,int cnt3,int sum){
	if(cnt1>n/2)return;
	if(cnt2>n/2)return;
	if(cnt3>n/2)return;
	if(k==n+1){
		ans=max(ans,sum);
		return;
	}
	if(a[k][1].id==1)dfs(k+1,cnt1+1,cnt2,cnt3,sum+a[k][1].x);
	else if(a[k][1].id==2)dfs(k+1,cnt1,cnt2+1,cnt3,sum+a[k][1].x);
	else if(a[k][1].id==3)dfs(k+1,cnt1,cnt2,cnt3+1,sum+a[k][1].x);
	if(a[k][2].id==1)dfs(k+1,cnt1+1,cnt2,cnt3,sum+a[k][2].x);
	else if(a[k][2].id==2)dfs(k+1,cnt1,cnt2+1,cnt3,sum+a[k][2].x);
	else if(a[k][2].id==3)dfs(k+1,cnt1,cnt2,cnt3+1,sum+a[k][2].x);
}
int dp[MAXN];
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&t);
	while(t--){
		scanf("%lld",&n);
		ans=0;
		int cnt1=0,cnt2=0,cnt3=0,s=0;
		for(int i=1;i<=n;i++){
			scanf("%lld %lld %lld",&a[i][1].x,&a[i][2].x,&a[i][3].x);
			a[i][1].id=1;
			a[i][2].id=2;
			a[i][3].id=3;
			sort(a[i]+1,a[i]+4,cmp);
			s+=a[i][1].x;
			if(a[i][1].id==1)cnt1++;
			else if(a[i][1].id==2)cnt2++;
			else if(a[i][1].id==3)cnt3++;
		}
		if(cnt1>n/2||cnt2>n/2||cnt3>n/2){
			int cm=0;
			if(cnt1>n/2)cm=1;
			else if(cnt2>n/2)cm=2;
			else cm=3;
			for(int j=0;j<=n/2+10;j++)dp[j]=0;
			for(int i=1;i<=n;i++){
				for(int j=n/2;j>=1;j--){
					if(a[i][1].id==cm)dp[j]=max(dp[j-1]+a[i][1].x,dp[j]+a[i][2].x);
					else dp[j]=max(dp[j-1]+a[i][2].x,dp[j]+a[i][1].x);
				}
				if(a[i][1].id==cm)dp[0]=dp[0]+a[i][2].x;
				else dp[0]=dp[0]+a[i][1].x;
			}
			printf("%lld\n",dp[n/2]);
		}else{
			printf("%lld\n",s);
		}
	}
	return 0;
} 
