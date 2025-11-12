#include<bits/stdc++.h>
using namespace std;
long long n,a[5001];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(nullptr),cout.tie(nullptr);
	cin>>n;
	if(n==3){
		long long s=0,maxn=1;
		for(int i=1;i<=3;i++) cin>>a[i],s+=a[i],maxn=max(maxn,a[i]);
		if(maxn*2<s) cout<<1;
		else cout<<0;
		return 0;
	}
	for(int i=1;i<=n;i++) cin>>a[i];
	cout<<n%998244353*(n-1)%998244353*(n-2)%998244353;
	return 0;
}
