#include<bits/stdc++.h>
using namespace std;
#define int long long
int net[5000006];
int w[500005];
int a[500005];
int maxn[500005];
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		w[i]=w[i-1]^a[i];
	}
	int ans=-1;
	for(int i=1;i<=n;i++){
		maxn[i]=maxn[i-1];
		if(w[i]==k){
			if(net[0])maxn[i]=max(maxn[i],maxn[net[w[i]^k]]+1);
			else maxn[i]=max(maxn[i],1ll);
			net[w[i]]=i;
			ans=max(ans,maxn[i]);
			continue;
		}
		if(net[w[i]^k]==0){
			net[w[i]]=i;
			continue;
		}
		maxn[i]=max(maxn[i],maxn[net[w[i]^k]]+1);
		net[w[i]]=i;
		ans=max(ans,maxn[i]);
	}
	cout<<ans;
	return 0;
}