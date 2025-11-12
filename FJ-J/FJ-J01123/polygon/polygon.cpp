#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=1e6+5,mod=998244353;
int n,a[N],dis[N],mj;
ll sum,ans;
bool cmp(int aa,int bb){
	return aa>bb;
}
void dfs(int ci,int p,int dmx,ll he){
	if(p>n)return;
	dfs(ci,p+1,dmx,he);
//	dis[ci]=a[p];
	dmx=max(dmx,a[p]);
	he+=a[p];
	ci++;
	if(ci==mj){
		if(he>2*dmx){
			ans++;
			ans%=mod;
		}
		return;
	}
//	if(he>2*dmx){
//		ll ja=((n-p)-(mj-ci)+1)%mod;
//		ans+=ja;
//		ans%=mod;
//		return;
//	}
	dfs(ci,p+1,dmx,he);
	return;
}
int main(){
//	freopen("polygon3.in","r",stdin);
//	freopen("polygon3.out","w",stdout);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum+=a[i];
	}
	sort(a+1,a+1+n,cmp);
	if(n<=3){
		if(sum>max(a[1],max(a[2],a[3]))*2)cout<<1;
		else cout<<0;
		return 0;
	}
	else{
		for(mj=3;mj<=n;mj++){
			dfs(1,1,0,0);
		}
	}
	cout<<ans+1;
	return 0;
}

