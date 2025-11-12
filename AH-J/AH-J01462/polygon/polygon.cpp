#include"bits/stdc++.h"
#define mod 998244353
using namespace std;
int n;
int a[100005];
int anss;
void dfs(int x,int sum,int mx,int cnt){
	if(x==n+1){
		if(cnt>=3&&sum>(mx<<1)){
			anss++;
			if(anss>=mod)
				anss-=mod;
		}
		return;
	}
	dfs(x+1,sum,mx,cnt);
	dfs(x+1,sum+a[x],a[x],cnt+1);
	return;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	if(a[n]==1){
		int ans=1;
		for(int i=1;i<=n;i++){
			ans<<=1;
			ans%=mod;
		}
		ans--;
		ans-=n;
		ans-=(n*(n-1))>>1;
		ans%=mod;
		ans+=mod;
		ans%=mod;
		printf("%d\n",ans);
		return 0;
	}
	dfs(1,0,0,0);
	printf("%d\n",anss);
	return 0;
}
