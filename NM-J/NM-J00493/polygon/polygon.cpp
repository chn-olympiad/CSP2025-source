#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a[5010],k,n,ans,cnt,c;
const ll mod=998244353;
bool f[5010];
//       个数               拼到now根 
void dfs(ll k,ll sum,ll ma,ll now){
	if(now==k+1){
		if(sum>2*ma){
			cnt++;
			cnt%=mod;
		}
	}else{
		for(ll i=1;i<=n;i++){
			if(f[i]==0){
				f[i]=1;
				dfs(k,a[i]+sum,max(ma,a[i]),now+1);
				f[i]=0;
			}
		}
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(ll i=1;i<=n;i++)cin>>a[i];
	for(ll i=3;i<=n;i++){
		dfs(i,0,0,1);
		ll p=1;
		for(ll j=1;j<=i;j++){
			p*=j;
		}
		c+=cnt/p;
		cnt=0;
	}
	cout<<c;
	
	return 0;
}
