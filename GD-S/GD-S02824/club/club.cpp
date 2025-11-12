//T1-target 55pts
#include<bits/stdc++.h>
#define int long long
#define N 205
#define M 100005
using namespace std;
int t,n,a[M][5],f[N][N][N],ans,b[M];
bool suba;
signed main(){
//	freopen("club4.in","r",stdin);
//	freopen("club.out","w",stdout);
	system("fc club4.ans club.out");
	scanf("%lld",&t);
	while(t--){
		ans=0;
		suba=1;
		memset(f,0,sizeof f);
		scanf("%lld",&n);
		for(int i = 1; i <= n; i++ ){
			scanf("%lld%lld%lld",&a[i][1],&a[i][2],&a[i][3]);
			if(a[i][2]!=0||a[i][3]!=0){
				suba=0;
			}
		}
		if(suba){
			for(int i = 1; i <= n; i++ ){
				b[i]=a[i][1];
			}
			sort(b+1,b+1+n,greater<int>());
			for(int i = 1; i <= n/2; i++ ){
				ans+=b[i];
			}
			printf("%lld\n",ans);
			continue;
		}
		for(int i = 1; i <= n; i++ ){//加入第i个人 
			for(int j = 0; j <= min(i,n/2); j++ ){//部门1 
				for(int k = 0; k <= min(i,n/2); k++ ){
					if(i-j-k>n/2) continue;
					if(j>0){
						f[j][k][i-j-k]=max(f[j][k][i-j-k],f[j-1][k][i-j-k]+a[i][1]);
					}
					if(k>0){
						f[j][k][i-j-k]=max(f[j][k][i-j-k],f[j][k-1][i-j-k]+a[i][2]);
					}
					if(i-j-k>0){
						f[j][k][i-j-k]=max(f[j][k][i-j-k],f[j][k][i-j-k-1]+a[i][3]);
					}
				}
			}
		}
		for(int i = 1; i <= n/2; i++ ){
			for(int j = 1; j <= n/2; j++ ){
				if(n-i-j>n/2) continue;
				ans=max(ans,f[i][j][n-i-j]);
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}

