#include<bits/stdc++.h>
using namespace std;
#define int long long
const int k=998244353;
int n,s,ans;
int a[5005],c[5005][5005];
void dfs(int x,int t,int sum,int maxx){
	if(t==0){
		if(sum>maxx*2) ++ans,ans%=k;
		return;
	}
	for(int i=x+1;i<=n-t+1;++i) dfs(i,t-1,sum+a[i],a[i]);
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	for(int i=0;i<=5000;++i)
		for(int j=0;j<=5000;++j){
			if(i==0||j==0||j==i) c[i][j]=1;
			else c[i][j]=(c[i-1][j]+c[i-1][j-1])%k;
		}
	scanf("%lld",&n);
	for(int i=1;i<=n;++i) scanf("%lld",&a[i]),s=max(s,a[i]);
	sort(a+1,a+1+n);
	if(s==1){
		int sum=0;
		for(int i=3;i<=n;i++) sum=(sum+c[n][i])%k;
		printf("%lld",sum);
		return 0;
	}
	if(n<=20){
		int ans=0;
		for(int t=0;t<pow(2,n);++t){
			int p=t,k=0,sum=0,maxx=0;
			while(p){
				++k;
				if(p%2){
					sum+=a[k];
					maxx=max(maxx,a[k]);
				}
				p/=2;
			}
			if(sum>maxx*2) ++ans;
		}
		printf("%lld",ans);
		return 0;
	}
	for(int cnt=3;cnt<=n;++cnt)
		for(int i=1;i<=n-cnt+1;++i)
			dfs(i,cnt-1,a[i],a[i]);
	printf("%lld",ans%k); 
	return 0;
} 
