#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int N=5e5+10;
int n,a[N],f[N],sum[N],k;
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)sum[i]=sum[i-1]^a[i];
	for(int i=1;i<=n;i++){
		for(int j=i;j>=1;j--){
			if((sum[i]^sum[j-1])==k){
				f[i]=max(f[i],f[j-1]+1);
			}
		}
	} 
	int ans=0;
	for(int i=1;i<=n;i++){
		ans=max(ans,f[i]);
	}
	cout<<ans;
	return 0;
}
