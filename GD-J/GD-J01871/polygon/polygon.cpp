#include <bits/stdc++.h>
using namespace std;
const int maxn=5010;
const int mod=998244353;
int cnt[100010];
long long a[maxn],f[maxn];

int main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	long long ans=0;
	cin >> n;
	memset(cnt,-1,sizeof(cnt));
	for(int i=1;i<=n;i++) cin >> a[i];
	sort(a+1,a+1+n);
	if(n<3) cout << ans << "\n";
	else if(n==3) {
		if(a[1]+a[2]+a[3]>2*a[3]) cout << 1 << "\n";
	    else cout << ans << "\n";
	}else {
		for(int i=1;i<n;i++) {
			if(cnt[a[i]+a[i+1]]==-1) cnt[a[i]+a[i+1]]=i;
		}
		f[0]=f[1]=f[2]=0;
		for(int i=3;i<=n;i++) {
			f[i]=2LL*f[i-1]%mod;
			int r=cnt[a[i]+1];
			if(r==-1) {
				int j=a[i];
				while(cnt[j]==-1) j++;
				if(cnt[j]<=i-2) {
					r=cnt[j];
					int m=i-r+1;
					f[i]=(f[i]+1LL*m*(m-1)/2)%mod;
				}
			}
		}
		cout << f[n]%mod << "\n";
	}
	return 0;
}
