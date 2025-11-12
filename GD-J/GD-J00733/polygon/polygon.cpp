#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N=5e3+10;
const int P=998244353;
int n,a[N];
LL f[N];
int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	f[0]=1; int mx=5e3+1; LL ans=0;
	for(int i=1;i<=n;i++) {
		for(int j=a[i]+1;j<=mx;j++) ans=(ans+f[j])%P;
		f[mx]=(f[mx]*2)%P;
		for(int j=mx-1;j>=0;j--) f[min(j+a[i],mx)]=(f[min(j+a[i],mx)]+f[j])%P;
//		for(int j=0;j<=15;j++) cout<<f[j]<<' '; cout<<'\n';
	}
	cout<<ans;
	return 0;
}
