#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,ans;
int a[5007];
long long jie[5007];
inline void dfs(int now,int mx,int sum,int choose){
	if(now>n){
		if(sum>2*mx&&choose>=3){
			printf("%d\n",choose);
			ans++;
		}
		return;
	}
	dfs(now+1,max(mx,a[now]),sum+a[now],choose+1);
	dfs(now+1,mx,sum,choose);
	return;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	int maxx=0;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		maxx=max(a[i],maxx);
	}
	if(maxx==1){
		for(int i=1;i<=n;i++){
			jie[i]=1;
			for(int j=1;j<=i;j++){
				jie[i]=(jie[i]%mod*j%mod)%mod;
			}
		}
		long long sum=0;
		for(int i=3;i<=n;i++){
			if(n-i==0){
				sum++;
				continue;
			}
			sum=(sum+(jie[n]/((jie[i]*jie[n-i])%mod)%mod)%mod)%mod;
		}
		printf("%lld",sum%mod);
		return 0;
	}
	sort(a+1,a+n+1);
	dfs(1,0,0,0);
	printf("%d",ans);
	return 0;
}
//#Shang4Shan3Ruo6Shui4
