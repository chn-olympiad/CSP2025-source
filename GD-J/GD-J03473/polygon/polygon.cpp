#include<bits/stdc++.h>
#define ll long long
const ll MOD=998244353;

using namespace std;
int n,ma=-1;ll ans;
int a[5010];

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		ma=max(ma,a[i]);
	}
	sort(a+1,a+1+n);
	if(n==3){
		if(a[1]+a[2]>a[3]) cout<<1;
		else cout<<0;
		return 0;
	}
	if(ma==1){
		n=n-2;
		for(int i=1;i<=n;++i){
		ans=(ans*i)%MOD;
		}
		cout<<ans%MOD;
		return 0;
	}
	
	
	return 0;
}
