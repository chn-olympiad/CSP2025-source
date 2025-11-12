#include<bits/stdc++.h>
using namespace std;
const int N=1e6+86;
const int mod=998244353;
int a[N],ans[N];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m; cin>>n>>m;
	string s; cin>>s;
	int res=0;
	for(int i=1;i<=n;++i){
		cin>>a[i]; if(a[i]==0) res++;
	}
	ans[1]=1;
	for(int i=2;i<=n;++i) ans[i]=ans[i-1]*i%mod;
	if(n-res<m) cout<<0;
	else cout<<ans[n];
	return 0;
}
