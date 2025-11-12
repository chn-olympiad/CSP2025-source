#include <bits/stdc++.h>
using namespace std;
const long long p=998244353;
long long n;
int a[5010];
int vis[5010];
int flag=0;
long long cnt=0;
bool f() {
	int sum=0;
	int mx=0;
	int t=0;
	for (int i=1;i<=n;i++) {
		if (vis[i]==1) {
			mx=max(mx,a[i]);
			t++;
			sum+=a[i];
		}
	}
	if ((mx*2<sum)&&(t>=3)) return 1;
	else return 0;
}
void dfs(int step) {
	if (step==n+1) {
		if (f()) {
			cnt++;
		}
		return ;
	}
	vis[step]=0;
	dfs(step+1);
	vis[step]=1;
	dfs(step+1);
	vis[step]=0;
	return ;
}
int main() {
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for (int i=1;i<=n;i++) {
		cin>>a[i];
		if (a[i]!=1) flag=1;
	}
	if (flag) {
		dfs(1);
		cout<<cnt%p;
	}
	else {
		long long sum=1;
		for (int i=0;i<n;i++) sum=(sum*2)%p;
		sum-=(n*(n-1)/2)%p;
		sum-=n;
		cout<<sum-1;
	}
	return 0;
}


