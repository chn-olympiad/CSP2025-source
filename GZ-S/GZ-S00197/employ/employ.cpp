//GZ-S00197 遵义市第四中学 戴文博
#include <bits/stdc++.h>
#define INF 998244353
using namespace std;
long long n,m;
long long ans=0;
long long a[1005];
long long sum[1005];
bool vis[1005];
string s;
long long dfs(long long day,long long suc,long long al,long long fail) {
	if(suc==al)return 1;
	if(n-day+1<al-suc+1)return 0;
	if(day==n+1)return 0;
	long long w=0;
	for(long long i=1; i<=n; i++) {
		if(vis[i])continue;
		vis[i]=1;
		if(a[i]<=sum[day]+fail) {
			w=((w%INF)+(dfs(day+1,suc,al,fail+1)%INF))%INF;
		} else {
			w=((w%INF)+(dfs(day+1,suc+1,al,fail)%INF))%INF;
		}
		vis[i]=0;
	}
	return w;
}
int main() {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	cin>>s;
	int len=s.size();
	for(int i=0; i<n; i++) {
		sum[i+1]=sum[i];
		if((s[i]-'0')==0) {
			sum[i+1]++;
		}
	}
	for(int i=1; i<=n; i++) {
		scanf("%lld",&a[i]);
	}
	if(m==n) {
		for(int i=0; i<n; i++) {
			if((s[i]-'0')==0) {
				cout<<0;
				return 0;
			}
		}
		ans=1;
		for(int i=n; i>=1; i--) {
			ans=((ans%INF)*(i%INF))%INF;
		}
		printf("%lld",ans);
	} else {
		if(!sum[n]) {
			ans=0;
			for(int i=m; i<=n; i++) {
				long long tmp=1;
				for(int j=n; j>=n-i+1; j--) {
					tmp=((tmp%INF)*(j%INF))%INF;
				}
				ans=((ans%INF)+(tmp%INF))%INF;
			}
			printf("%lld",ans);
		} else {
			for(int i=m; i<=n; i++){
				int tmp=(dfs(1,0,i,0)%INF);
				if(!tmp){
					break;
				}
				ans=((ans%INF)+(tmp%INF))%INF;
			}
			printf("%lld",ans);
			return 0;
		}
	}
	return 0;
	fclose(stdin);
	fclose(stdout);
}

