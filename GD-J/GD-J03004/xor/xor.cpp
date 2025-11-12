#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll a[6000010],cnt[6000010];
int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	ll cnt1=0,cnt2=0;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
		if(a[i])cnt1++;
		else cnt2++;
	}
	if(cnt1==0&&k==0)cout<<n;
	else if(cnt1==0&&k==1)cout<<0;
	return 0;
}
