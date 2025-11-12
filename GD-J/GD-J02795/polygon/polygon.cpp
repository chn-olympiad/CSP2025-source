#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
int n;
long long ans;
int a[5005];
long long sum;
int maxn;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	bool p=1;
	for(int i=1; i<=n; i++){
		cin>>a[i];
		if(a[i]!=1) p=0;
		sum+=a[i];
		maxn=max(maxn,a[i]);
	}
	if(sum>maxn*2) ans++;
	if(p==1){
		cout<<n;
		return 0;
	}
	cout<<ans%mod;
	return 0;
}
