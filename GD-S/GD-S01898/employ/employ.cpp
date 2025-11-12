#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
bool v[505];
int a[505];
bool used[505];
int ans=0;
int n,m;
void dfs(int x=0,int lose=0){
	if(n-lose<m)return ;
	if(x==n){
		++ans;
		if(ans==mod)ans=0;
		return ;
	}
	for(int i=1;i<=n;i++){
		if(used[i])continue;
		used[i]=true;
		dfs(x+1,lose+(lose>=a[i]||v[x+1]==0?1:0));
		used[i]=false;
	}
	return ;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	bool special_data=true;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		char c;
		cin>>c;
		v[i]=bool(c=='1');
		special_data&=v[i];
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(special_data){
		long long ans=0;
		for(int i=2;i<=n;i++)ans=(ans*i)%mod;
		cout<<ans;
		return 0;
	}
	dfs();
	cout<<ans;
	return 0;
}
