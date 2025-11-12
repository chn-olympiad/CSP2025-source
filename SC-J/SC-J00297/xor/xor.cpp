#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e6+50;
int f[N],cnt[N],a[N];
vector<int> q[N];
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		cnt[i]=cnt[i-1]^a[i];
		q[cnt[i]].push_back(i);
	}
	for(int l=1;l<=n;l++){
		int cntr=cnt[l-1]^k;
		f[l]=max(f[l],f[l-1]);
		if(q[cntr].size()==0) continue;
		if(lower_bound(q[cntr].begin(),q[cntr].end(),l)==q[cntr].end()) continue;
		int idx=lower_bound(q[cntr].begin(),q[cntr].end(),l)-q[cntr].begin();
		idx=q[cntr][idx];
		f[idx+1]=max(f[idx+1],(f[l]+1));
	}
	int ans=0;
	for(int i=1;i<=n+1;i++) ans=max(ans,f[i]);
	cout<<ans<<endl;
}
/*
4 3
2 1 0 3

*/