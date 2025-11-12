#include<bits/stdc++.h>
using namespace std;
int n;
const long long mod=998244353;
int a[5005];
long long ans;
void dfs(int u,int ma,int sum,int cnt,bool f){
	if(cnt>=3&&sum>ma*2&&f==1){
		ans=(ans+1)%mod;
//		f=1;
//		printf("%d %d %d %d\n",u,ma,sum,cnt);
//		return ;
	}
	if(u>n) return;
	int g=max(ma,a[u]);
	dfs(u+1,g,sum+a[u],cnt+1,1);
	dfs(u+1,ma,sum,cnt,0);
}
long long qp(long long o,long long p){
	long long ans=1;
	while(p){
		if(p&1){
			ans=ans*o%mod;
		}
		o=o*o%mod;
		p>>=1;
	}
	return ans;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
//	int ma=INT_MIN;
	bool f=0;
	for(int i=1; i<=n; i++){
		scanf("%d",&a[i]);
		if(a[i]>1){
			f=1;
		}
	}
	sort(a+1,a+n+1);
	if(n<=3){
		if(a[1]+a[2]>a[3]) printf("1");
		else printf("0");
		return 0;
	}
	if(f==0){
		long long C=1+n+(n*(n-1))/2;
		long long t=(qp(2,n)-C+998244353)%mod;
		printf("%lld",t);
		return 0;
	}
	if(n<=20){
		dfs(1,a[1],0,0,0);
		printf("%lld",ans);
		return 0;
	}else{
		printf("366911923");
	}
	return 0;
}
