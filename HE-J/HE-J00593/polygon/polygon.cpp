#include<cstdio>
#include<algorithm>

const int mod=998244353;
unsigned int n,a[5100],b[5010],map[5010][5010];
long long f[510],vis[510];
long long ans;
void dfs(int step,int x,int k){
	if(step>k){
		int t=0;
		for(int i=1;i<k;i++) t+=f[i];
		if(t>f[k]) ans++;
		return;
	}
	for(int i=x+1;i<=n;i++){
		if(!vis[i]){
			f[step]=a[i];
			vis[i]=1;
			dfs(step+1,i,k);
			vis[i]=0;
		}
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%u",&n);
	map[0][0]=1;
	for(int i=1;i<=5000;i++){ map[i][0]=1; for(int j=1;j<=i;j++) map[i][j]=(map[i-1][j-1]+map[i-1][j])%mod;}
	for(int i=1;i<=n;i++) scanf("%u",&a[i]);
	std::sort(a+1,a+1+n);
	for(int i=1;i<=n;i++) b[i]=a[i]+b[i-1];
	if(n<=20){
		for(int i=3;i<=n;i++) dfs(1,0,i);
		printf("%lld",ans%mod);
		return 0;
	}
	for(int i=3;i<=n;i++){
		for(int k=2;k<i;k++){
			int x=0;
			for(int j=k;j<i;j++){
				if(b[j]-b[j-k]>a[i]){
					x=j-k+1;
					ans=(ans+map[i-x][k])%mod;
					break;
				}
			}
		}
	}
	printf("%lld",ans);
	return 0;
}
