#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll md=998244353,ans,n,a[5005];
void dfs(ll x,ll sum,ll cnt,bool use){
	if(3-cnt>n-x+1) return;
	if(cnt>=3&&sum>a[x-1]*2&&use){
		ans++;
		ans%=md;
	}
	if(x>n) return;
	dfs(x+1,sum+a[x],cnt+1,true);
	dfs(x+1,sum,cnt,false);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	dfs(1,0,0,false);
	printf("%lld",ans);
	return 0;
}
