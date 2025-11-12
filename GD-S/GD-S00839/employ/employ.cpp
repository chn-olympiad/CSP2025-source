#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,m;
string s;
int d[520];
int c[520];
bitset<520> vis;
int tmp[520];
int ans;
void dfs(int depth){
	if(depth>n){
		//cerr<<"clear:\n";
		int cnt=0,bck=0;
		for(int i=1;i<=n;i++){
			if(d[i]==0||bck>=c[tmp[i]])bck++;
			else cnt++;
			//cerr<<i<<" "<<tmp[i]<<" "<<c[tmp[i]]<<" "<<cnt<<"\n";
		}
		if(cnt>=m){
			ans++;
		}
		return;
	}
	for(int i=1;i<=n;i++){
		if(vis[i])continue;
		tmp[depth]=i;
		vis[i]=true;
		dfs(depth+1);
		vis[i]=false;
	}
	return;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		d[i]=s[i-1]-'0';
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	if(n<=11){
		dfs(1);
		cout<<ans;
		return 0;
	}
	bool f1=true;
	for(int i=1;i<=n;i++){
		if(f1!=1){
			f1=false;
			break;
		}
	}
	if(m==1){
		int cnt=0;
		for(int i=1;i<=n;i++){
			if(c[i]!=0)cnt++;
		}
		long long ans=1;
		if(cnt<m){
			cout<<0;
			return 0;
		}
		for(int i=1;i<=cnt;i++){
			ans=(1ll*ans*i)%mod;
			//cerr<<i<<":"<<ans<<"\n";
		}
		for(int i=1;i<=n-cnt;i++){
			ans=(1ll*ans*i)%mod;
			//cerr<<i<<":"<<ans<<"\n";
		}
		cout<<ans;
		return 0;
	}
	return 0;
}
//rp ++
