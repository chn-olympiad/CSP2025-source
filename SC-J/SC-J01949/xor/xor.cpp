#include<bits/stdc++.h>
#define int long long
const int N=2e6+5;
using namespace std;
int a[N];
int f[N],t[N]; 
int n,k,ans;
//N方破百万，暴力碾表算！ 
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]); 
		t[i] = (t[i-1] ^ a[i]);
	}
	f[0] = 0;
	
	for(int i=1;i<=n;i++){
		int mmax = 0;
		for(int j=0;j<i;j++){
			mmax = max(mmax,f[j]);
			if((t[i] ^ t[j]) == k){
				f[i] = max(f[i],mmax+1);
			}
//			cout<<i<<" "<<j<<" "<<(t[i] ^ t[j])<<"\n";
		}
//		cout<<f[i]<<"\n";
		ans = max(ans,f[i]);
	}
	cout<<ans;
	return 0;
}
// Why do we only have one chance at live

