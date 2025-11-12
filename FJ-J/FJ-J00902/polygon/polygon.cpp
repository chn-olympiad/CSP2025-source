#include<bits/stdc++.h>
using namespace std;
int n,a[5001];
int vis[5001];
long long ans=0;
void dfs(int now,int sum,int ma,int prev){
	if(now>=3){
		if(sum>ma*2){
			ans++;
		}
	}
	for(int i=prev+1;i<=n;i++){
		vis[i]=1;
		dfs(now+1,sum+a[i],max(ma,a[i]),i);
		vis[i]=0;
	}
}
int main(){
//	freopen("polygon.in","r",stdin);
//	freopen("polygon.out","w",stdout);
//	for(int i=1;i<=20;i++) printf("100 ");
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	if(n==3){
		if(a[1]+a[2]>a[3]&&abs(a[1]-a[2])<a[3]) printf("1\n");
		else printf("0\n");
		return 0;
	}
	sort(a+1,a+1+n);
	dfs(0,0,0,0);
	printf("%lld\n",ans%998%244%353);
//	printf("%lld\n",ans);
	return 0;
}

