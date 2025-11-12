#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,k,a[N],q[N],p[N],dp[N];
map<int,int> f;
signed main(){
	cin.tie(0);
	cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	f[0]=-1;
	for(int i=1;i<=n;i++){
		q[i]=q[i-1]^a[i];
		f[q[i]]=i;
		if(f[k^q[i]]){
			p[i]=f[k^q[i]]+1;
			if(p[i]==0) p[i]++;
//			cout<<p[i]<<"->"<<i<<"\n";
		}
	}
	for(int i=1;i<=n;i++){
		if(p[i]) dp[i]=max(dp[i-1],dp[p[i]-1]+1);
		else dp[i]=dp[i-1];
	}
	cout<<dp[n];
	return 0;
}
