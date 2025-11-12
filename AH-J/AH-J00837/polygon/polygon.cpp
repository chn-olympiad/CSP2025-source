#include<bits/stdc++.h>
using namespace std;
int n;
const int N=5005;
int a[N],ans,maxn;
int mod=998244353;
void dfs(int now,int ch,int num,int maxn,int sum){
	if(now>n+1) return ;
	if(ch==num){
		if(sum>2*maxn) ans=(ans+1)%mod;
		return ;
	}
	dfs(now+1,ch,num,maxn,sum);
	dfs(now+1,ch+1,num,max(maxn,a[now]),sum+a[now]);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		maxn=max(maxn,a[i]);
	}
	if(maxn==1){
		for(int i=3;i<=n;i++){
			int sum=1,clc=1;
			for(int j=n;j>=n-i+1;j--){
				sum=sum*j%mod;
			}
			for(int j=i;j>=1;j--) clc=clc*j%mod;
			ans+=(sum/clc)%mod;
		}
		printf("%d\n",ans%mod);
		return 0;
	}
	for(int i=3;i<=n;i++){
		dfs(1,0,i,0,0);
	}
	printf("%d\n",ans%mod);
	return 0;
}
