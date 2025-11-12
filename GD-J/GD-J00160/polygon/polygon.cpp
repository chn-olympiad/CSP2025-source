#include<bits/stdc++.h>
#define N 5005
#define int long long
#define md 998244353
using namespace std;
int n,a[N],f[N],sum[N],ans,g[N];
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);f[0]=1;
	for(int i=1;i<=n;i++){
		if(i>=3) (ans+=sum[a[i]+1])%=md;f[5001]+=f[5001];
		for(int j=0;j<=5000;j++){
			if(a[i]+j>5000) (g[5001]+=f[j])%=md;
			else (g[a[i]+j]+=f[j])%=md;
		}
		for(int j=0;j<=5001;j++) (f[j]+=g[j])%=md,g[j]=0;
		sum[5001]=f[5001];
		for(int j=5000;j>=0;j--) sum[j]=(f[j]+sum[j+1])%md;
	}
	cout<<ans;
	return 0;
}
