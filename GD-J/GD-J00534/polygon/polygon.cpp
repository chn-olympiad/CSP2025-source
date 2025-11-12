#include<bits/stdc++.h>
using namespace std;
long long n,ans,t;
int a[5005];
bool c[5005];
long long dfs(int dep,long long sum,int maxl,int di){
	int cnt=0;
	if(dep==0)	return 1;
	for(int i=di-dep+1;i<n;++i){
		if(c[i]==0){
			if(dep==1 && !(sum+a[i]>=2*maxl))	continue;
			c[i]=1;
			cnt+=dfs(dep-1,sum+a[i],max(maxl,a[i]),di);
			c[i]=0;
		}
	}
	return cnt;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	scanf("%lld",&n);
	for(int i=1;i<=n;++i){
		scanf("%lld",&a[i]);
	}
	for(int i=3;i<=n;++i){
		ans+=dfs(i,0,-1,i);
	}
	printf("%lld",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
