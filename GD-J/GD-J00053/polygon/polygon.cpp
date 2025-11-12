#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int a[5005],used[5005],cnt[5005],maxx1;int n;
long long ans=0;
void dfs(int mde,int dep,int maxx,int ans1,int nw){
	if(nw==n&&dep!=mde) return;
	if(dep>=mde){
		if(ans1<=2*maxx) return ;
		ans++;
//		for(int i=1;i<=n;i++) printf("%d ",cnt[i]);
//		puts(" ");
//		memset(cnt,0,sizeof(cnt));
		ans%=mod;
		return;
	}
	for(int i=nw;i<=n;i++){
//		if(ans1<=2*maxx&&maxx>a[i]) continue;
//		if(i==nw&&dep<mde-1) return ;
		if(!used[i]){
			if(maxx<a[i]) maxx1=a[i];
			else maxx1=maxx;
			used[i]=1;
			cnt[dep+1]=a[i];
			dfs(mde,dep+1,maxx1,ans1+a[i],i);
			used[i]=0;
		}
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		maxx1=max(maxx1,a[i]);
	}
	if(maxx1<=1){
		for(int i=3;i<=n;i++){
			ans=(ans+n-i+1)%mod;
		}
		printf("%lld\n",ans);
		return 0;
	} 
	for(int i=3;i<=n;i++) dfs(i,0,0,0,1);
	printf("%lld\n",ans);
	return 0;
}

