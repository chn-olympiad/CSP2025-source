#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
long long n,m,ans,a[505],p[505];
string s;bool flag,vis[505];
void dfs(int x){
	if(x>n){
		int cnt=0;
		for(int i=1;i<=n;i++){
			if(i-cnt-1>=a[p[i]]) continue;
			else if(s[i-1]=='1') cnt++;
		}
		if(cnt>=m) ans=(ans+1)%mod;
		return;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			p[x]=i;
			dfs(x+1);
			vis[i]=0;
		}
	}
	return;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=0;i<s.size();i++)
		if(s[i]=='0'){
			flag=1;
			break;
		}
	for(int i=1;i<=n;i++) cin>>a[i];
	if(flag==0){
		ans=1;
		for(int i=1;i<=n;i++)
		ans=ans*(min(n,a[i]+1))%mod;
		cout<<ans;
		return 0;
	}
	dfs(1);
	cout<<ans;
	return 0;
}
