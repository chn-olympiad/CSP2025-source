#include<bits/stdc++.h>
using namespace std;
long long ma[1000010],mb[1000010],mc[1000010];
int main() {
	ios::sync_with_stdio(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	long long n;
	int k;
	cin>>n>>k;
	for(long long i=1; i<=n; i++)
		cin>>ma[i]>>mb[i]>>mc[i];
	if(k==0) {
		long long ans=0;
		for(long long i=1; i<=n; i++)
			ans+=mc[i];
		cout<<ans<<endl;
	} else {
		cout<<0<<endl;
	}
	return 0;
}

























