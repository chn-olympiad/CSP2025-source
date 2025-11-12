#include <bits/stdc++.h>
using namespace std;
const int N=210,NN=1e5+10;
int T,n,m,ans;
int dp[N][N][N];
struct node{
	int x,y,z;
}a[NN];

bool cmp_case_A(node A,node B){
	return A.x>B.x;
}

bool cmp_case_B(node A,node B){
	return (A.x-A.y)>(B.x-B.y);
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		ans=0;
		cin>>n;
		bool is_case_A=1,is_case_B=1;
		for(int i=1;i<=n;i++){
			cin>>a[i].x>>a[i].y>>a[i].z; 
			if(a[i].y||a[i].z) is_case_A=0;
			if(a[i].z) is_case_B=0;
		}
		if(is_case_A){
			sort(a+1,a+n+1,cmp_case_A);
			for(int i=1;i<=n/2;i++){
				ans+=a[i].x;
			}
			printf("%lld\n",ans);
			continue;
		}
		else if(is_case_B){
			sort(a+1,a+n+1,cmp_case_B);
			for(int i=1;i<=n/2;i++) ans+=a[i].x;
			for(int i=n/2+1;i<=n;i++) ans+=a[i].y;
			printf("%lld\n",ans);
			continue;
		} 
		else if(n<=200){
			memset(dp,0,sizeof(dp));
			for(int i=1;i<=n;i++){
				for(int j=0;j<=i&&j<=n/2;j++){
					for(int k=0;k<=i-j&&k<=n/2;k++){
						int l=i-j-k;
						if(l<0||l>n/2) continue;
						if(j>0)dp[i][j][k]=max(dp[i][j][k],dp[i-1][j-1][k]+a[i].x);
						if(k>0)dp[i][j][k]=max(dp[i][j][k],dp[i-1][j][k-1]+a[i].y);
						if(l>0)dp[i][j][k]=max(dp[i][j][k],dp[i-1][j][k]+a[i].z);
					}
				}
			}
			
			for(int i=0;i<=n/2;i++){
				for(int j=0;j<=n/2;j++){
					int l=n-i-j;
					if(l<0||l>n/2) continue;
					ans=max(ans,dp[n][i][j]);
				}
			}
			cout<<ans<<endl;	
		}
		else{
			sort(a+1,a+n+1,cmp_case_B);
			for(int i=1;i<=n/2;i++){
				ans+=max(a[i].x,a[i].z);
			}
			for(int i=n/2+1;i<=n;i++){
				ans+=max(a[i].y,a[i].z);
			}
			printf("%lld\n",ans);
		}
	}
	
	return 0;
} 
