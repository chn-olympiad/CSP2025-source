#include<bits/stdc++.h>
using namespace std;
const int mode=998244353;
long long n,a[50005],b[50005],ans,bmax;
long long powe(int x){
	long long pow2=1,shu=2;
	while(x>0){
		if(x%2==0){
			x=x/2;
			shu=shu*shu%mode;
		}else{
			pow2=pow2*shu%mode;
			shu=shu*shu%mode;
			x=x/2;	
		}
	}
	return pow2;
}
void dfs(int h,long long sum,long long maxe){
	if(h==n+1){
		if(sum>maxe*2){
			ans=(ans+1)%mode;
		}
		return ;
	}
	if(sum>bmax*2 && h>3){
		long long add=powe(n-h+1)%mode;
		ans=(ans+add)%mode;
		return ;
	}
	b[h]=1;
	if(maxe==0){
		dfs(h+1,sum+a[h],a[h]);
	}else{
		dfs(h+1,sum+a[h],maxe);
	}
	b[h]=0;
	dfs(h+1,sum,maxe);
	return ;
}
bool cmp(long long x,long long y){
	return x>y;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1,cmp);
	bmax=a[1];
	dfs(1,0,0);
	printf("%lld",ans);
	return 0;
}
