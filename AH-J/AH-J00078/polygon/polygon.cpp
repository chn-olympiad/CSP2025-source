#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=998244353;
int a[5010];
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==3){
		int tmp=0,maxn=INT_MIN;
		for(int i=1;i<=n;i++){
			tmp+=a[i];
			maxn=max(maxn,a[i]);
		}
		cout<<(tmp>maxn*2)?1:0<<'\n';
		return 0;
	}else{
		int ans=0;
		int s=1;
		for(int i=1;i<=n;i++){
			s=s*i%mod;
		}
		for(int i=3;i<=n;i++){
			int tmp=1,tmps=1;
			for(int j=1;j<=i;j++){
				tmp=tmp*j%mod;
			}
			for(int j=1;j<=n-i;j++){
				tmps=tmps*j%mod;
			}
			ans=ans+(s/tmp/tmps)%mod;
		}
		cout<<ans<<'\n';
		return 0;
	}
	return 0;
}
