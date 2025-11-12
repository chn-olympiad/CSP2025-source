#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll MOD=998244353;
int n,a[5005];
ll ans;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int len=3;len<=n;len++){
		ll tans=1;
		for(int i=n;i>=n-len+1;i--) tans=tans*i;
		for(int i=1;i<=len;i++) tans=tans/i;
		ans=(ans+tans)%MOD;
	}
	printf("%lld",ans); 
	return 0;
}
