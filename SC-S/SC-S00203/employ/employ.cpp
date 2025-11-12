#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
int n,m;
string s;
int a[100001];
int b[100001];
bool vis[100001];
int ans;
void dfs(int pos){
	if(pos==n+1){
		int cnt=0;
		for(int i=1;i<=n;i++){
			if(s[i-1]=='0'||b[i]<=cnt)cnt++;
		}
		//cout<<n-cnt<<"\n";
		if(n-cnt>=m){
			ans++;
			ans%=mod;
		}
		return;
	}
	for(int i=1;i<=n;i++){
		if(vis[i])continue;
		vis[i]=1;
		b[pos]=a[i];
		dfs(pos+1);
		vis[i]=0;
	}
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(1);
	cout<<ans;
	return 0;
}