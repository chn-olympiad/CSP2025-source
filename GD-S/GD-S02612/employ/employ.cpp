#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+5,mod=998244353;
int n,m;
bool a[N];
int c[N];
int b[N];
bool f[N];
ll ans=0;
void dfs(int s){
	if(s==n+1){
		int sum=0;
		for(int i=1;i<=n;i++){
			//cout<<b[i]<<' '<<sum<<' '<<c[b[i]]<<'\n';
			if(n-sum<m) break;
			if(!a[i] || sum>=c[b[i]]) sum++;
		}
		//cout<<'\n'; 
		if(n-sum>=m) ans++;
		return;
	}
	for(int i=1;i<=n;i++){
		if(f[i]) continue;
		f[i]=1;
		b[s]=i;
		dfs(s+1);
		f[i]=0;
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>n>>m;
	int cnt=0;
	string s;
	cin>>s;
	for(int i=1;i<=n;i++){
		a[i]=s[i-1]-'0';
		if(a[i]) cnt++;
	}
	for(int i=1;i<=n;i++)
		cin>>c[i];
	if(cnt<m){
		cout<<0;
		return 0;
	}
	if(n==m){
		ans=1;
		for(int i=1;i<=n;i++)
			ans=ans*i%mod;
		cout<<ans;
		return 0;
	}
	dfs(1);
	cout<<ans;
	return 0;
}  
