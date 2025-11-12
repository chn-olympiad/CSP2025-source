#include<bits/stdc++.h>
using namespace std;
int n,k;
long long a[200005],maxn=0;
void dfs(int t,long long ar,long long ans) {
	if(t>n) {
		maxn=max(maxn,ar);
		return ;
	}
	//cout<<t<<" "<<ar<<" "<<ans<<" "<<maxn<<endl;
	if(ans==k) dfs(t+1,ar+1,a[t+1]);
	else dfs(t+1,ar,ans^a[t+1]);
}
int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++) {
		cin>>a[i];
	}
	dfs(1,0,a[1]);
	cout<<maxn;
	return 0;
}
