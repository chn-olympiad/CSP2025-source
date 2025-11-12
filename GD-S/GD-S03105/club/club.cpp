#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll T,n;
ll a[100005],b[100005],c[100005];
ll ans=0;
void dfs(ll dep,ll sum,ll x,ll y,ll z){
	if(dep==n+1){
		ans=max(ans,sum);
		return;
	}
	if(x<n/2) dfs(dep+1,sum+a[dep],x+1,y,z);
	if(y<n/2) dfs(dep+1,sum+b[dep],x,y+1,z);
	if(z<n/2) dfs(dep+1,sum+c[dep],x,y,z+1);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>T;
	while(T--){
		cin>>n;
		ans=0;
		ll bk=0,ck=0;
		for(int i=1;i<=n;++i){
			cin>>a[i]>>b[i]>>c[i];
			if(b[i]==0) bk++;
			if(c[i]==0) ck++;
		}
		if(bk==n and ck==n){
			sort(a+1,a+n+1);
			for(int i=1;i<=n/2;i++) ans+=a[n-i+1];
		}
		else dfs(1,0,0,0,0);
		cout<<ans<<endl;
	}
	return 0;
}
