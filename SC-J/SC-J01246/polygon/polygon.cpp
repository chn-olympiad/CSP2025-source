//polygon
#include<bits/stdc++.h>
using namespace std;

const int N=5e3+5;
const int mod=998244353;

int n,ans;
int a[N],f[N];

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;++i) cin>>a[i];
	sort(a+1,a+n+1);
	f[0]=1;
	for(int i=1;i<=n;++i){
		for(int j=a[i]+1;j<=5001;++j) (ans+=f[j])%=mod;
		for(int j=5001;j>=0;--j) (f[min(j+a[i],5001)]+=f[j])%=mod;
	}
	cout<<ans;
	return 0;
}