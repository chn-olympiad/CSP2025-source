#include<cstdio>
using namespace std;
const long long mod=99824453;
long long a[5005],ans;
int n;
inline long long mx(long long h,long long g){
	return h>g?h:g;
}
void dfs(int k,long long sum,long long maxx,int cnt){
	if(k==0){
		if(sum>maxx*2)++ans,ans%=mod;
		return;
	}
	if(cnt>n)return;
	dfs(k-1,sum+a[cnt],mx(maxx,a[cnt]),cnt+1);
	dfs(k,sum,maxx,cnt+1);
	return;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	bool bo;
	bo=1;
	for(int i=1;i<=n;++i){
		scanf("%lld",&a[i]);
		if(a[i]!=1)bo=0;
	}
	if(n==3){
		long long sum=0,maxx=-1;
		for(int i=1;i<=n;++i){
			sum+=a[i];
			if(a[i]>maxx)maxx=a[i];
		}
		if(sum>(2*maxx))printf("1\n");
		else printf("0\n");
		return 0;
	}
	if(bo){
		long long ans=1;
		for(int i=3;i<=n;++i){
			long long cnt;
			for(int j=1;j<=i;++j){
				cnt=cnt*(n-i+j)%mod;
			}
			ans+=cnt;
			ans%=mod;
		}
		printf("%lld\n",ans);
		return 0;
	}
	for(int i=3;i<=n;++i){
		dfs(i,0,-1,1);
	}
	printf("%lld\n",ans);
	return 0;
}
