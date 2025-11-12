#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a[5005],ans;
const int mod=998244353;
void dfs(int now,int sum,int last){
	if(now==n+1){
		if(sum>last*2&&sum>0) ans++;
		ans%=mod;
		return;
	}
	//ัก
	dfs(now+1,sum+a[now],a[now]);
	//ฒปัก
	dfs(now+1,sum,last); 
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	dfs(1,0,0);
	printf("%lld",ans%mod);
	return 0;
}
