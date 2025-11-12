#include <iostream>
using namespace std;

int a[5010];
long long ans=0;

void dfs(int n,int tl,int ml,int m) {
	if (n==0) {
		if ((m>=3)&&(tl>2*ml)) {
			ans++;
			ans%=998244353;
		}
		return;
	}
	dfs(n-1,tl+a[n],max(ml,a[n]),m+1); // xuan
	dfs(n-1,tl,ml,m); // bu xuan
	return;
}

int main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	for (int i=1;i<=n;i++) {
		cin>>a[i];
	}
	dfs(n,0,0,0);
	cout<<ans;
	return 0;
}