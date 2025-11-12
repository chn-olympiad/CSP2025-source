#include <bits/stdc++.h>
using namespace std;
long long n,m,c[505],nn[505],ans,mod=998244353,tn[505];
bool s[105],u[505];
string ss; 
bool A=true;
void dfs (long long k) {
	if (k==n) {
		long long pans=0;
		for (int i=1;i<=n;i++) {
			tn[i]=tn[i-1];
			tn[i-1]=0;
			if (s[i]&&tn[i]<c[nn[i]]) pans++;
			else tn[i]++;
		}
		tn[n]=0;
		if (pans>=m) {
			ans++;
		}
		
		return ;
	}
	for (int i=1;i<=n;i++) {
		if (!u[i]) {
			u[i]=true;
			nn[k+1]=i;
			dfs(k+1);
			nn[k+1]=0;
			u[i]=false;
		}
	}
	return ;
}
int main () {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	cin>>ss;
	for (int i=0;i<n;i++) {
		s[i+1]=(ss[i]-'0');
		if (!s[i+1]) A=false;
	}
	for (int i=1;i<=n;i++) {
		cin>>c[i];
	}
	if (A) {
		for (int i=1;i<=n;i++) ans=ans*i%mod;
		cout<<ans;
		return 0;
	}
	else if (n<=10) {
		dfs(0);
		cout<<ans;
		return 0;
	}
	return 0;
}

