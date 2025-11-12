#include<bits/stdc++.h>
using namespace std;
int n,ans,a[5005];
const int mod=998244353;
void dfs(int now,int sum,int mx,int xuan){
	if(xuan>=3&&sum>2*mx){
		ans=(ans+1)%mod;
	}
	if(now>n) return;
	dfs(now+1,sum,mx,xuan);
	dfs(now+1,sum+a[now],max(mx,now),xuan+1);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	if(n<=3){
		int mx=0;
		for(int i=1;i<=3;i++){
			mx=max(mx,a[i]);
		}
		if(a[1]+a[2]+a[3]>2*mx) printf("1");
		else printf("0");
		return 0;
	}
	dfs(1,0,0,0);
	printf("%d",ans);
	return 0;
}
