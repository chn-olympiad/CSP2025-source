#include<bits/stdc++.h>
using namespace std;
const long long N=5e5+5;
long long n,k,a[N],ans;
bool vis[N];
void dfs(long long now,long long sum){
	if(sum==k){
		ans++;
		if(now+1<=n)dfs(now+1,a[now+1]);
		return;
	}
	dfs(now+1,sum^a[now+1]);
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>k;
	for(long long i=1;i<=n;i++)cin>>a[i];
	if(n<=1e3){
		dfs(1,a[1]);
		cout<<ans;
	}
	return 0;
}
