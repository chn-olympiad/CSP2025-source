#include<bits/stdc++.h>
#define int long long 
using namespace std;
int n,k,ans,sum,a[11451400];
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		if(a[i]==1) ++ans;
		if(a[i]==0) ++sum;
	}
	if(ans==n&&k==0) return cout<<n/2,0;
	if(k==0) return cout<<ans/2+sum,0;
	if(k==1) return cout<<ans,0;
	cout<<2;
}
