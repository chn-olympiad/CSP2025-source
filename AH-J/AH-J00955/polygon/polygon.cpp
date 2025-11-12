#include<bits/stdc++.h>
using namespace std;
int n,a[5005],sum[5005],cnt,maxn,summ;
typedef long long ll;
const ll mod=998244353;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	maxn=-1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum[i]=sum[i-1]+a[i];
		maxn=max(maxn,a[i]);
	}
	if(n<3){
		cout<<0;
		return 0;
	}
	if(n==3){
		summ=0;
		maxn=-1;
		for(int i=1;i<=n;i++){
			maxn=max(maxn,a[i]);
			summ+=a[i];
		}
		if(maxn*2<summ) cout<<1;
		else cout<<0;
		return 0;
	}
	if(maxn==1){
		ll ans=0ll;
		for(ll i=3;i<=n;i++){
			for(ll j=n-i+1;j>=1;j--){
				ans+=j;
			}
			ans%=mod;
		}
		cout<<ans;
		return 0;
	}
	maxn=-1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			if((i-j)<2) continue;
			int sumc=sum[i]-sum[j-1];
			maxn=-1;
			for(int k=j;k<=i;k++){
				maxn=max(maxn,a[k]);
			}
			if(maxn*2<sumc){
				//cout<<i<<' '<<j<<'\n';
				cnt++;
			}
		}
	}
	cout<<cnt;
	return 0;
}
