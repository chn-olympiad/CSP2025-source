#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 5000;
const int mod = 998244353;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin.tie(nullptr)->sync_with_stdio(false);
	int n,sum=0;
	cin>>n;
	vector<int> a(n);
	for(int i=1;i<=n;i++){
		cin>>a[i-1];
		sum+=a[i-1];
	}
	sort(a.begin(),a.end());
	ll ans=0;
	for(int i=0;i<(1<<n);i++){
		int tot=0,mx=0;
		for(int j=0;j<n;j++)
			if(i&(1<<j))
				tot+=a[j],mx=a[j];
		if(2*mx<tot)
			++ans;
	}
	cout<<ans%mod;
	return 0;
}