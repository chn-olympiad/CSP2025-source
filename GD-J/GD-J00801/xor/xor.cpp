#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,k,ans;
int a[500005],p,sum[500005],t,f[500005],t1;
signed main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i],sum[i]=(sum[i-1]^a[i]);
	for(int j=1;j<=n;j++){
		if(f[j]) continue;
		if(a[j]==k){
			ans++,f[j]=1,t=j;
			continue;
		} 
		for(int l=j-1;l>t;l--){
			if(((sum[j]^sum[l-1])==k)&&!f[j]&&!f[l]){
				t=j;ans++;f[j]=f[l]=1;break;
			} 
		}
	}
	cout<<ans;
}
