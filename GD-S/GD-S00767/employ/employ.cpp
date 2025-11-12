#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[505],vis[505],ans[505],an;
string s; 
bool f;
bool check(){
	int cnt=0,rs=0;
	for(int i=1;i<=n;i++){
		if(rs>n-m)return false;
		if(rs>=a[ans[i]])rs++;
		else{
			if(s[i-1]=='0')rs++;
		    else cnt++;
		}
	}
	return cnt>=m;
}
void dfs(int cs){
	if(cs==n){
		if(check()){
			an++;
		}
		an%=998244353;
		return;
	}
	for(int i=1;i<=n;i++){
		if(vis[i])continue;
		vis[i]=1;
		ans[cs+1]=i;
		dfs(cs+1);
		vis[i]=0;
	}
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]!='1')f=1;
	}
	for(int i=1;i<=n;i++){ 
		cin>>a[i];
	}
	if(f==0){
		an=1;
		for(int i=n;i>=1;i--){
			an*=i;
			an%=998244353;
		}
		cout<<an%998244353;
		return 0;
	}
	dfs(0);
	cout<<an;
	return 0;
}
