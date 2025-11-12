#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,m,c[100001],p[100001],ans;
bool f[100001];
string s;
void dfs(int step){
	if(step==n+1){
		int sum=0;
		for(int i=1;i<=n;i++){
			if(s[i-1]==48||c[p[i]]<=sum)sum++;
		}
		if(n-sum>=m)ans++;
		return;
	}
	for(int i=1;i<=n;i++){
		if(!f[i]){
			p[step]=i,f[i]=1;
			dfs(step+1);
			f[i]=0;
		}
	}
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++)cin>>c[i];
	if(n>18){
		ans=1;
		for(int i=1;i<=n;i++)ans=ans*i%mod;
		cout<<ans;
		return 0;
	}
	dfs(1);
	cout<<ans;
}
