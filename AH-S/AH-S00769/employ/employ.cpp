#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353;
int n,m;
int c[510];
string s;
bool f[510];
int ans=0;
vector<int> v;
bool check(){
	int d=0;
	for(int i=0;i<n;i++){
		if(s[i]=='0'||d>=c[v[i]]){d++;continue;}
	}
	return (d<=n-m);
}
void dfs(int step){
	if(step==n+1){
		if(check())ans++;
		return ;
	}
	for(int i=1;i<=n;i++){
		if(!f[i]){
			v.push_back(i);
			f[i]=1;
			dfs(step+1);
			f[i]=0;
			v.pop_back();
		}
	}
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++)cin>>c[i];
	if(m==n){
		for(int i=0;i<n;i++)if(s[i]=='0'){cout<<0;return 0;}
		for(int i=1;i<=n;i++)if(c[i]==0){cout<<0;return 0;}
		int t=1;
		for(int i=1;i<=n;i++){
			t=t*i%mod;
		}
		cout<<t;
		return 0;
	}
	dfs(1);
	cout<<ans%mod;
	return 0;
}
