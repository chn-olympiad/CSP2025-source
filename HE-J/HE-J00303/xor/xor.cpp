#include<bits/stdc++.h>
#define int long long
using namespace std;
template<typename T>inline void read(T&x) {
	x=0;
	char c;
	int sgin=1;
	do {
		c=getchar();
		if(c=='-')sgin=-1;
	} while(!isdigit(c));
	do {
		x=(x<<3)+(x<<1)+(c&15);
		c=getchar();
	} while(isdigit(c));
	x*=sgin;
}
int n,k,a[500010],sum[500010],dp[500010][2];
vector<int> v[500010];
map<int,int> vis;
signed main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	read(n);
	read(k);
	for(int i=1; i<=n; i++) {
		read(a[i]);
	}
	v[0].push_back(0);
	for(int i=1; i<=n; i++) {
		sum[i]=(a[i]^sum[i-1]);
		if(vis[sum[i]]==0&&sum[i]!=0) {
			vis[-1]++;
			vis[sum[i]]=vis[-1];
		}
		v[vis[sum[i]]].push_back(i);
	}
	int ans=0;
	for(int i=1; i<=n; i++) {
		dp[i][0]=max(dp[i-1][0],dp[i-1][1]);
		int cnt=vis[(sum[i]^k)];
		for(auto j:v[cnt]){
			if(j+1<=i){
				dp[i][1]=max(dp[i][1],dp[j+1][0]+1);
			}
			else break;
		}
		ans=max({ans,dp[i][0],dp[i][1]});
	}
	printf("%lld",ans);
	return 0;
}
