#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e4+5,mod=998244353;
ll sit1[N],sit2[N],ovr;
int a[N],bot[N];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int mx=0,n; cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		mx=max(mx,a[i]);
	} 
	sort(a+1,a+n+1);
	
	ll ans=0;
	sit1[0]=1; sit2[0]=1;
	for(int i=1;i<=n;++i){
		//calculate
		for(int j=a[i]+1;j<=mx;++j) ans+=sit2[j]-bot[j];
		(ans+=ovr)%=mod;
//		cout<<i<<" <-> "<<ans<<'\n';
//		for(int j=1;j<=mx;++j){
//			cout<<j<<' '<<sit2[j]<<'\n';
//		}
		//update
		for(int j=0;j<=mx-a[i];++j){
			(sit2[j+a[i]]+=sit1[j])%=mod;
		}
		(ovr*=2)%=mod;
		for(int j=mx-a[i]+1;j<=mx;++j){
			(ovr+=sit1[j])%=mod;
		}
		for(int j=1;j<=mx;++j){
			sit1[j]=sit2[j];
		}
		bot[a[i]]++;
	}
	cout<<ans;
	return 0;
}