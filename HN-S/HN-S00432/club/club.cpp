#include<bits/stdc++.h>
using namespace std;
/*
1.n个新员,三个部门
2.若将第 i (1 ≤ i ≤ n) 个新成员分配到了第 di ∈ {1, 2, 3} 个部门，则该
分配方案的满意度为 
3.不.存.在.一个部门被分配多.于. n/2 个新成员

满意度的最大值。
*/
typedef long long ll;
const int N=1e5;
ll T;
ll n;
ll a[N][4];
ll dp[N][4];
ll w[N][4];

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&T);
	while(T--){
		scanf("%lld",&n);
		for(int i=1;i<=n;i++){
			ll u,v,b;
			scanf("%lld%lld%lld",&u,&v,&b);
			a[i][1]=u;
			a[i][2]=v;
			a[i][3]=b;
		}
		int z=n/2;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				w[i][j]=z;
			}
		}
		memset(dp,0,sizeof(dp));
		for(int i=1;i<=n;i++){
			ll ans=dp[i-1][3];
			for(int k=1;k<=3;k++){
				//for(int j=1;j<=z;j++){
				//cout<<dp[i][k];
				dp[i][k]=dp[i][k-1];
		        	if(w[i][k]){
		        		if(dp[i-1][3]+a[i][k]>ans){  
						ans=dp[i-1][3]+a[i][k];
		        		dp[i][k]=ans;
		        		w[i][k]--;
		        		w[i][k-1]++;
						} 
					}
				//}
				
			}
			//cout<<dp[1][3]<<" ";
		}
		printf("%lld\n",dp[n][3]);
		//printf("%lld\n",a[1][3]);
	}
	//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	return 0;
}
