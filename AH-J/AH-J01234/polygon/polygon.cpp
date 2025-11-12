#include<bits/stdc++.h>
#define LL long long
using namespace std;
const LL N=5010,MOD=998244353;
LL n,ans,maxa;
LL a[N],ajc[N];
void dfs(LL dep,LL sum,LL maxaa,LL cnt){
	if(dep>n){
		if(sum>2*maxaa && cnt>=3) ans=(ans+1)%MOD;
		return;
	}
	dfs(dep+1,sum+a[dep],max(maxaa,a[dep]),cnt+1);
	dfs(dep+1,sum,maxaa,cnt);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(LL i=1;i<=n;i++) cin>>a[i],maxa=max(maxa,a[i]);
	if(maxa==1){
		ajc[0]=1;
		for(LL i=1;i<=n;i++) ajc[i]=(ajc[i-1]*i);
		for(LL i=3;i<=n;i++){
			ans=(ans+ajc[n]/ajc[i]/ajc[n-i])%MOD;
		}
		cout<<ans<<endl;
		return 0;
	}
	dfs(1,0,0,0);
	cout<<ans<<endl;
	return 0;
}
