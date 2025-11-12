#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+10;
int a[N],sum[N];
int n,k,ans;
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]^a[i];
	}
	for(int l=1,r=1;r<=n;r++){
		for(int i=l;i<=r;i++){
			if((sum[r]^sum[i-1])==k){
				ans++; l=r+1;
				break;
			}
		}
	}
	cout<<ans<<"\n";
	return 0;
}
