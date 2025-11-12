#include<bits/stdc++.h>

using namespace std;

const long long p=998244353;

long long n,m;
string s;
long long a[505],c[505];
long long vis[505];
long long ans;

void dfs(long long u,long long mm,long long gi) {
	if(u>n) {
		if(mm>=m)
			ans=(ans+1)%p;
		return;
	}
	for(long long i=1; i<=n; i++) {
		if(vis[i])continue;
		vis[i]=1;
		if(gi>=c[i]) {
			dfs(u+1,mm,gi+1);
		} else if(a[u]==1) {
			dfs(u+1,mm+1,gi);
		} else if(a[u]==0) {
			dfs(u+1,mm,gi+1);
		}
		vis[i]=0;
	}
}

int main() {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(long long i=0; i<s.size(); i++) {
		if(s[i]=='1')a[i+1]=1;
	}
	for(long long i=1; i<=n; i++) {
		cin>>c[i];
	}
	dfs(1,0,0);
	cout<<ans<<endl;
	return 0;
}
