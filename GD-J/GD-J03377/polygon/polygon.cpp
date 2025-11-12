#include<bits/stdc++.h>
using namespace std;
int n;
int a[5001];
int c[5001];
long long ans=0;
inline int sum_max(int q){
	int ma=0;
	for(int i=1;i<=q;i++){
		ma=max(ma,c[i]);
	}
	return ma;
}
inline void dfs(int q,int i,int qian){
	if(i>q){
		long long sum=0;
		for(int j=1;j<=q;j++){
			sum+=c[j];
		}
		if(sum>2*sum_max(q)){
			ans=(ans+1)%998244353;
			return;
		}
	}
	for(int j=qian+1;j<=n;j++){
		c[i]=a[j];
		dfs(q,i+1,j);
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=3;i<=n;i++){
		dfs(i,1,0);
	}
	printf("%lld",ans);
	return 0;
}
