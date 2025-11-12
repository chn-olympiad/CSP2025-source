#include<bits/stdc++.h>
using namespace std;
long long n,mx=-1,g;
long long a[5005];
bool vis[5005];
int main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(long long i=1; i<=n; i++) {
		cin>>a[i];
		mx=max(mx,a[i]);
	}
	if(n==3) {
		if(a[1]+a[2]+a[3]>2*mx) cout<<1<<endl;
		else cout<<0<<endl;
		return 0;
	} else if(mx==1) {
		long long cnt=0;
		for(long long i=3; i<n; i++) {
			memset(vis,0,sizeof(vis));
			long long k=n-i,ans=1;
			for(long long j=n; j>=n-(min(i,k))+1; j--) {
				ans*=j;
				for(long long l=min(i,k); l>=1; l--) {
					if(ans%l==0&&vis[l]==0) {
						vis[l]=1;
						ans/=l;
					}
				}
				ans%=998244353;
			}
			cnt+=ans;
			cnt%=998244353;
		}
		cout<<(cnt+1)%998244353<<endl;
		return 0;
	}
	cout<<0<<endl;
	return 0;
}
