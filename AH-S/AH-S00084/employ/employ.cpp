#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,le[505],pa[505],p[505],mod=998244353;
bool f[505];
ll jc[505],ans;
bool A(){
	for (int i=1;i<=n;i++)
		if (le[i]==0) return 0;
	return 1;
}
void dfs(int k){
	if (k==n+1){
		int ret=0;
		for (int i=1;i<=n;i++){
			if (le[i]==0||ret>=pa[p[i]]) ret++;
		}
		//cerr<<ret<<'\n';
		ans+=(n-ret)>=m;
	} else {
		for (int i=1;i<=n;i++){
			if (!f[i]){
				p[k]=i;	f[i]=1;
				dfs(k+1);
				f[i]=0;
			}
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	jc[0]=1;
	for (int i=1;i<=500;i++) jc[i]=jc[i-1]*i%mod;
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		char c; cin>>c;
		le[i]=c-'0';
	}
	for (int i=1;i<=n;i++) cin>>pa[i];
	if (m==n){
		for (int i=1;i<=n;i++){
			if (le[i]==0||pa[i]==0){
				cout<<0;
				return 0;
			}
		}
		cout<<jc[n];
	} else {
		dfs(1);
		cout<<ans;
	}
	
}
