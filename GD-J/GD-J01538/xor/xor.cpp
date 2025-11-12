#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5,M=1.1e6;
int a[N],n,S,f[N],sum[N];
int get(int l,int r) {return sum[r]^sum[l-1];}
priority_queue<int> q[M];
signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>S;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]^a[i];
	q[0].push(0);
	for(int i=1;i<=n;i++) {
		f[i]=f[i-1];
		int sumj=S^sum[i];
		if(!q[sumj].empty()) f[i]=max(f[i],q[sumj].top()+1);
		q[sum[i]].push(f[i]);
	}
	int ans=0;
	for(int i=1;i<=n;i++) ans=max(ans,f[i]);
	cout<<ans;
}
