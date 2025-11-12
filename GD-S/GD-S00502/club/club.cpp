#include<cstdio>
#include<cstring>
#include<algorithm>
#define int long long
using namespace std;
const int maxn=1e5+5;
const int maxm=5;
int a[maxn][maxm],b[maxn],cnt[maxm],n,m,t,ans;
void dfs(int x,int sum){
	if(x>m){
		ans=max(ans,sum);
	}
	for(int i=1;i<=3;i++){
		if(cnt[i]<m){
			cnt[i]++;
			dfs(x+1,sum+a[x][i]);
			cnt[i]--;
		}
	}
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&t);
	while(t--){
		scanf("%lld",&n);
		m=n>>1;
		ans=0;
		int tmp=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				scanf("%lld",&a[i][j]);
			}
			if(a[i][2]==0 && a[i][3]==0){
				tmp++;
			}
		}
		if(tmp==n){
			for(int i=1;i<=n;i++){
				b[i]=a[i][1];
			}
			sort(b+1,b+n+1);
			for(int i=n;i>m;i--){
				ans+=b[i];
			}
			printf("%lld\n",ans);
			continue;
		}
		dfs(1,0);
		printf("%lld\n",ans);
	}
	return 0;
}
