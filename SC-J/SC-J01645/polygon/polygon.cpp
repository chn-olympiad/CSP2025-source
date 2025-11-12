#include<bits/stdc++.h>
using namespace std;
long long n;
long long len[5001];
long long ans;
bool all[5001];
long long note[5001];
long long tol;
long long needmin;
long long gs[5001];
void dp(long long cs,long long gd) {
	if (cs>gd) {
		long long ma=LONG_LONG_MIN;
		long long tin=1;
		tol=0;
		for (int i=1;i<=gd;i++) {
			tol+=len[note[i]];
			ma=max(ma,len[note[i]]);
		}
		if (tol>(ma*2)) {
			gs[gd]++;
		}
		gs[gd]=gs[gd]%998244353;
		return;
	}
	for (int i=1;i<=n;i++) {
		if (!all[i]) {
			note[cs]=i;
			all[i]=true;
			dp((cs+1),gd);
			all[i]=false;
			note[cs]=0;
		}
	}
	return;
}
int main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for (int i=1;i<=n;i++) cin>>len[i];
	for (int i=3;i<=n;i++) dp(1,i);
	for (int i=3;i<=n;i++) {
		needmin=1;
		for (int j=2;j<=i;j++) needmin=(needmin*j)%998244353;
		ans+=(gs[i]/needmin);
		ans=ans%998244353;
	}
	cout<<ans;
	return 0;
}