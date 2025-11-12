#include <bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,a[N],sum[N],k,ans[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
//	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	sum[1]=a[1];
	for(int i=2;i<=n;i++) sum[i]=sum[i-1]^a[i];
//	for(int i=1;i<=n;i++) cout<<sum[i]<<' ';
	for(int i=1;i<=n;i++){
		ans[i]=max(ans[i],ans[i-1]);
		for(int j=0;j<=n-i;j++){
			int r=i+j;
			int ll=sum[r]^sum[i-1];
			if(ll==k){
				//cout<<i<<' '<<r<<'\n';
				ans[r]=max(ans[r],ans[i-1]+1);
			}
		}
	}
	cout<<ans[n];
	return 0;
}