#include<bits./stdc++.h>
#define int long long
using namespace std;
const int mod=998244353;
int n,a[5010],sum,ans;
bool f[5010];
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];	
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		sum+=a[i];
		if(i>=3){
			if(sum>a[i]*2){
				ans++;
			}
			for(int j=1;j<=i;j++){
				if(sum-a[j]>a[i]*2){
					ans++;
				}
			}
		}
	}
	cout<<ans%mod;
	return 0;
}
