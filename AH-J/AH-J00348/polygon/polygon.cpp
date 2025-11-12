#include<bits/stdc++.h>
using namespace std;
int n,a[5005];
bool f[5005];
const long long M=998244353;
long long ans=0;
void dfs(int now,int ma,int sum){
	if(now==n+1){
		if(2*ma<sum){
			ans++;
			ans%=M;
		}
		return;
	}
	f[now]=1;
	dfs(now+1,max(ma,a[now]),sum+a[now]);
	f[now]=0;
	dfs(now+1,ma,sum);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	int maxa=0;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		maxa=max(maxa,a[i]);
	}
	if(maxa==1){//15~20测试点
		long long ans=0;
		for(int i=3;i<=n;i++){
			ans+=n-i+1;
			ans%=M;
		}
		printf("%lld",ans);
		return 0;
	}
	dfs(1,0,0);//1~10测试点
	printf("%lld",ans);
	return 0;
}
