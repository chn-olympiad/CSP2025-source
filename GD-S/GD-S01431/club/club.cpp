#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n;
const int N=1e5+5;
int s[N][5];
ll ans=0;
int f1,f2;
int a[N];
struct edge{
	int a,b,sum;
	bool operator <(const edge &A)const{
		return sum>A.sum;
	}
}b[N];
void dfs(int now,int a,int b,int c,ll sum){
	if(now>n){
		ans=max(ans,sum);
		return ;
	}
	if((a+1)*2<=n){
		dfs(now+1,a+1,b,c,sum+s[now][1]);
	}
	if((b+1)*2<=n){
		dfs(now+1,a,b+1,c,sum+s[now][2]);
	}
	if((c+1)*2<=n){
		dfs(now+1,a,b,c+1,sum+s[now][3]);
	}
}
void solve(){
	ans=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=3;j++){
			scanf("%d",&s[i][j]);
			//a[j][i]=s[i][j];
			//dp[i][j]=0;
		}
		if(s[i][2]==0&&s[i][3]==0)f1++;
		if(s[i][3]==0)f2++;
	//	dp[i][0]=0;
	}
	if(n<=30){
		dfs(1,0,0,0,0ll);
		printf("%lld\n",ans);
		return ;
	}else{
		if(f1==n){
			for(int i=1;i<=n;i++)a[i]=s[i][1];
			sort(a+1,a+n+1);
			for(int i=1;i*2<=n;i++)ans+=a[i];
			printf("%lld\n",ans);
		}else if(f2==n){
			for(int i=1;i<=n;i++){
				b[i]={s[i][1],s[i][2],s[i][1]+s[i][2]};
			}
			sort(b+1,b+n+1);
			int sa=0,sb=0;
			for(int i=1;i<=n;i++){
				if(b[i].a>b[i].b&&sa*2<=n){
					ans+=b[i].a;
					sa++;
				}else{
					ans+=b[i].b;
				}
			}
			printf("%lld",ans);
		}else{
			dfs(1,0,0,0,0ll);
			printf("%lld\n",ans);
			return ;
		}
	}
//	//dfs(1,0,0,0,0ll);
//	//memset(dp,0,sizeof(dp));
//	for(int i=1;i<=n;i++){
//		for(int j=i-1;j>=0;j--){
//			for(int k=1;k<=3;k++){
//				if(2*(dp[j][k]+1)<=n){
//					//cout<<dp[j][k]+1<<endl;
//					if(dp[j][0]+s[i][k]>dp[i][0]){
//						dp[i][0]=dp[j][0]+s[i][k];
//						dp[i][k]=dp[j][k]+1;
//						for(int l=1;l<=3;l++){
//							if(l!=k)dp[i][l]=dp[j][l];
//						}
//					//	cout<<dp[i][3]<<endl;
//					}
//				}
//			}
//		}
//		//cout<<dp[i][3]<<endl;
//		printf("%d a:%d b:%d c:%d \n",dp[i][0],dp[i][1],dp[i][2],dp[i][3]);
//	}
//	//for(int i=1;i<=3;i++)ans=max(ans,dp[n][i]);
//	printf("%d a:%d b:%d\n",dp[n][0],dp[n][1],dp[n][2]);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;scanf("%d",&t);
	while(t--)solve();
	return 0;
}
