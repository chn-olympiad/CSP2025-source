#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
long long fc[505],a[505],b[505],f[505],ans;
int n,m;
string s;
void dfs(int x){
	if(x>n){
		int cnt=0,lost=0;
		for(int i=1;i<=n;i++){
			if(lost>=a[b[i]] || s[i]=='0') lost++;
			else cnt++;
		}
		if(cnt>=m) ans++;
		return;
	}
	for(int i=1;i<=n;i++){
		if(f[i]) continue;
		f[i]=1;
		b[x]=i;
		dfs(x+1);
		f[i]=0;
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	fc[0]=1;
	for(int i=1;i<=500;i++) fc[i]=fc[i-1]*i%mod;
	s=" "+s;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(m==n){
		for(int i=1;i<=n;i++) if(s[i]=='0' || a[i]==0){cout<<0;return 0;}
		cout<<fc[n];
		return 0;
	}
	if(m==1){
		int id=-1;
		for(int i=1;i<=n;i++) if(s[i]=='1') id=i;
		if(id==-1){cout<<0;return 0;}
		long long cnt=0;
		for(int i=1;i<=n;i++) if(a[i]>=id) cnt++; 
		cout<<cnt*fc[n-1]%mod;
		return 0;
	}
	bool flag=1;
	for(int i=1;i<=n;i++) if(s[i]=='0') flag=0;
	if(flag){
		int cnt=0;
		for(int i=1;i<=n;i++) if(a[i]==0) cnt++;
		if(n-cnt<m){cout<<0;return 0;}
		cout<<fc[n];
		return 0;
	}
	dfs(1);
	cout<<ans;
	return 0;
}
