#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MOD=998244353;
int n;
int a[5005];
int mx=-1;
int ans,ty,tz;
void dfs(int num,int sum,int mxx,int gs){
	if(num==n+1){
		if(gs>=3){
			if(sum>mxx*2){
				ans=(ans+1)%MOD;
			}
		}
		return;
	}
	dfs(num+1,sum+a[num],max(mxx,a[num]),gs+1);
	dfs(num+1,sum,mxx,gs);
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		mx=max(mx,a[i]);
	}
	if(mx==1){
		for(int i=3;i<=n;i++){
			ty=1;
			tz=1;
			for(int j=n-i+1;j<=n;j++){
				ty=(ty*j)%MOD;
				tz=(tz*(j-n+i))%MOD;
			}
			ans=(ans+(ty/tz))%MOD;
		}
		cout<<ans;
		return 0;
	}
	dfs(1,0,-1,0);
	cout<<ans;
	return 0;
} 
