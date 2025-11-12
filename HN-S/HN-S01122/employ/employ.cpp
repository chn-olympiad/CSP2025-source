#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int mod=998244353;
int ans,c[510],n,m;
string s;
bool vis[510];
void dfs(int cur,int sum){//sum表示未录取的人数 
	if(n-sum<m){
		return ;
	}
	if(cur==n+1){
		if(n-sum>=m){
			ans=(ans+1)%mod;
		} 
		return ;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]==false){
			vis[i]=true;
			if(sum>=c[i] or s[cur]=='0'){
				dfs(cur+1,sum+1);
			}else{
				dfs(cur+1,sum);
			}
			vis[i]=false;
		}
	}
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	s='#'+s;
	bool f=true;
	for(int i=1;i<=n;i++){
		cin>>c[i];
		if(s[i]=='0'){
			f=false;
		}
	}
	if(m==n and f==false){
		cout<<"0";
		return 0;
	}
	if(f==true){
		ans=1;
		for(int i=1;i<=n;i++){
			ans=(ans*i)%mod;
		}
		cout<<ans;
		return 0;
	}
	dfs(1,0);
	cout<<ans;
	return 0;
}

