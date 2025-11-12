#include<bits/stdc++.h>
using namespace std;
long long n,a[5005],s=0,t=0;
bool v[5005];
int dfs(long long ans) {
	s++;
	if(ans==t) {
		return s;
	}
	for(int i=1; i<=n; i++) {
		if(!v[i]&&ans+a[i]>a[i]*2) {
			v[i]=1;
			dfs(ans+a[i]);
			v[i]=0;
		}
	}
}
int main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	if(n<3) cout<<0;
	else {
		for(int i=1; i<=n; i++)
			cin>>a[i];
		for(int i=1; i<=n; i++)
			t+=a[i];
		sort(a+1,a+n+1);
		if(n==3) {
			if(a[1]+a[2]>a[3]) cout<<1;
			else cout<<0;
		} else cout<<dfs(1);
	}
	return 0;
}
