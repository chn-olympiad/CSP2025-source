#include<bits/stdc++.h> 
using namespace std;
const long long mod=998244353;
bool book[5001];
long long a[50001];
long long n=20,ans,t;
void dfs(long long k,long long z,long long ma,long long cnt){
	if(!k){
		if(cnt>2*ma)ans++;
		return ;
	} 
	for(long long i=z;i<=n;i++){
		if(!book[i]){
			book[i]=1; 
			dfs(k-1,i,max(ma,a[i]),cnt+a[i]);
			book[i]=0;
		}
	}
	return ;
}
long long yh[5015][5015];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	bool flag=0;
	scanf("%d",&n);
	for(long long i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(a[i]>1)flag=1;
	}
	if(!flag){
		yh[0][0]=1;
		for(long long i=1;i<=5010;i++){
			for(long long j=0;j<=i;j++){
				yh[i][j]=yh[i-1][j]+yh[i-1][j-1];
				yh[i][j]%=mod;
			}
		}
		for(long long i=3;i<=n;i++){
			ans+=yh[n][i];
			ans%=mod;
		}
		printf("%lld",ans%mod);
		return 0;
	}
	for(long long i=3;i<=n;i++){
		t=0;
		dfs(i,1,-1,0);
	}
	printf("%lld",ans%mod);
	return 0;
}
