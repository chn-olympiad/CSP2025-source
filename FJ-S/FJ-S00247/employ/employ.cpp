#include<bits/stdc++.h>
using namespace std;
int n,m;
int p=998244353;
int s[1000];
int c[1000];
int t[1000];
int lb[1000];
long long ans;
int dl[1000];
int jc() {
	int now=0;
	for(int i=1; i<=n; i++) {
		if(s[i]==0||c[dl[i]]<=now)now++;
//		cout<<dl[i]<<" "<<now<<'\n';
	}
//	cout<<'\n'<<now<<'\n';
	return (now<=n-m);
}
void dfs(int gs) {
	if(gs==n+1) {
		ans+=jc();
		return ;
	}
	int sg=0;
	for(int i=lb[0]; i<=n; i=lb[i]) {
		dl[gs]=i;
		int cc=lb[sg];
		lb[sg]=lb[i];
		dfs(gs+1);
		lb[sg]=cc;
		sg=i;
	}
	return ;
}
int main() {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	lb[0]=1;
	for(int i=1; i<=n; i++) {
		lb[i]=i+1;
		char a;
		cin>>a;
		s[i]=a-'0';
		s[0]+=s[i];
	}
	int gs=0;
	for(int i=1; i<=n; i++)cin>>c[i],gs+=(c[i]==0),t[c[i]]++;
	if(gs>n-m) {
		cout<<0;
		return 0;
	}
	if(n<=20) {
		dfs(1);
		cout<<ans;
	}
	else cout<<0;
	return 0;
}
