#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,m,ans,c[505],a[505],vis[505];
string s;
bool check(){
	int cnt=0,sum=0;
	for(int i=1;i<=n;i++){
		if(c[a[i]]<=cnt){
			cnt++;
			continue;
		}
		if(s[i-1]=='0') cnt++;
		else sum++;
	}
	return sum>=m;
}
void dfs(int k){
	if(k>n){
		if(check()){
			ans++;
			ans%=mod;
		}
		return ;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			a[k]=i;
			dfs(k+1);
			vis[i]=0; 
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	bool f=1;
	for(auto c:s){
		if(c=='0'){
			f=0;
			break;
		}
	}
	if(f){
		ans=1;
		for(int i=1;i<=n;i++){
			ans*=i;
			ans%=mod;
		}
		cout<<ans;
		return 0;
	}
	else{
		for(int i=1;i<=n;i++) cin>>c[i];
		dfs(1);
		cout<<ans;
	}
	return 0;
}

