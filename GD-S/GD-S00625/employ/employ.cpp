#include<bits/stdc++.h>
using namespace std;
int n,m;
string s;
int c[1000];
bool use[1000];
long long ans;
void dfs(int h,int cnt) {
	if(cnt==h) {
		ans++;
		ans%=998244353;
		return;
	}
	for(int i=1; i<=n; i++) {
		if(use[i]==false) {
			use[i]=true;
			dfs(h,cnt+1);
			use[i]=false;
		}
	}
	return;
}
int main() {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1; i<=n; i++) {
		cin>>c[i];
	}
	dfs(n,0);
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
