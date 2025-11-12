#include<bits/stdc++.h>
using namespace std;
long long n,a[5003],q[5003],cnt,he,ans;
void dfs(long long x,long long mx) {
	if(cnt>=3) {
		if(he>mx*2) ans++;
	}
	for(long long i=x+1; i<=n; i++) {
		q[cnt++]=a[i];
		he+=a[i];
		dfs(i,max(mx,a[i]));
		he-=a[i];
		cnt--;
	}
}
int main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(long long i=1; i<=n; i++) {
		cin>>a[i];
	}
	dfs(0,0);
	cout<<ans;
	return 0;
}
