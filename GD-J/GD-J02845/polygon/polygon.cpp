#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=5010,M=5001,p=998244353;
ll n,f[N]={},a[N]={},ans=0;
void solve(){
	cin>>n;
	for(ll i=1;i<=n;cin>>a[i++]);
	sort(a+1,a+1+n);
	f[0]=1;
	for(ll i=1;i<=n;i++){
		for(ll j=M;j>=0;j--){
			if(j>a[i]) (ans+=f[j])%=p;
			(f[min(M,j+a[i])]+=f[j])%=p;
		}
	}
	cout<<ans;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	solve();
	return 0;
}
