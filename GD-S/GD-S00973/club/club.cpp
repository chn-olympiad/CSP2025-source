#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+5;
ll dp[2][205][205];
int n,t,now,last;
ll a[N][4];
ll ans;
bool check1(){
	bool f=1;
	for(int i=1;i<=n;i++){
		if(a[i][2]!=0||a[i][3]!=0) f=0;
	}
	return f;
}
bool cmp(int A,int B){
	return A>B;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout); 
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		ans=0;
		now=0,last=1;
		memset(dp,0,sizeof(dp));
		for(int i=1;i<=n;i++) scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);
		if(check1()){
			vector<int> v;
			for(int i=1;i<=n;i++) v.push_back(a[i][1]);
			sort(v.begin(),v.end(),cmp);
			for(int i=0;i<=n/2-1;i++) ans+=v[i];
			printf("%lld\n",ans);
			continue;
		}
		for(int k=1;k<=n;k++){
			now^=1,last^=1;
			for(int i=0;i<=k;i++){
				for(int j=0;j+i<=k;j++){
					
					if(i>=1&&j>=1)dp[now][i][j]=max(dp[last][i-1][j]+a[k][1],max(dp[last][i][j-1]+a[k][2],dp[last][i][j]+a[k][3]));
					else if(i>=1) dp[now][i][j]=max(dp[last][i-1][j]+a[k][1],dp[last][i][j]+a[k][3]);
					else if(j>=1) dp[now][i][j]=max(dp[last][i][j-1]+a[k][2],dp[last][i][j]+a[k][3]);
					else dp[now][i][j]=dp[last][i][j]+a[k][3];
//					printf("%d %d %d %lld\n",k,i,j,dp[i][j]);
				}
			}
		}
		for(int i=0;i<=n/2;i++){
			for(int j=0;j<=n/2;j++){
				if(i+j<n/2) continue;
				ans=max(ans,dp[now][i][j]);
//				printf("%lld ",dp[i][j]);
			}
//			printf("\n");
		}
		printf("%lld\n",ans);
	}
	return 0;
}

