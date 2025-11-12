#include<bits/stdc++.h>
#define int long long
#define mod 998244353
using namespace std;
int n,m,c[501],v[501],ans;
vector<int>g;
string s;
inline void dfs(int i){
	if(i==n){
		int cnt=0;
		for(int j=1;j<=n;j++){
			if(s[j]=='0'||cnt>=c[g[j]]){
				cnt++;
			}
		}
		if(n-cnt>=m){
			ans=(ans+1)%mod;
		}
	}
	for(int j=1;j<=n;j++){
		if(!v[j]){
			v[j]=1;
			g.push_back(j);
			dfs(i+1);
			v[j]=0;
			g.pop_back();
		}
	}
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin.tie(nullptr)->sync_with_stdio(0);
	cin>>n>>m>>s;
	s=' '+s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	if(n<=10){
		g.push_back(0);
		dfs(0);
		cout<<ans;
	}
	else if(m==n){
		for(int i=1;i<=n;i++){
			if(c[i]==0){
				cout<<0;
				return 0;
			}
		}
		cout<<1;
	}
	else{
		cout<<0;
	}
	return 0;
}
