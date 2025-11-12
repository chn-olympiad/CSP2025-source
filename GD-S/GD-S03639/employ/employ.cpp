#include<bits/stdc++.h>
using namespace std;
int n,m;
char s[50005];
map<long long,bool>vis,v;
map<long long,long long>a;
long long ans,mod=998244353;
void dfs(int x,int out) {
	if(x>n) {
		if(n-out>=m)ans++;
		return;
	}
	for(int i=1; i<=n; i++) {
		if(!vis[i]) {
			vis[i]=1;
			if(v[x]==1 or out>=a[i])dfs(x+1,out+1);
			else dfs(x+1,out);
			vis[i]=0;
		}
	}
}
int main() {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	bool p=0;
	for(int i=1; i<=n; i++) {
		if(s[i-1]-'0'==0) {
			v[i]=1;
			p=1;
		}
	}
	for(int i=1; i<=n; i++)cin>>a[i];
	if(!p) {
		ans=1;
		for(long long i=1; i<=n; i++) {
			ans*=i;
			ans%=mod;
		}
		cout<<ans;
		return 0;
	}
	dfs(1,0);
	cout<<ans;
}
