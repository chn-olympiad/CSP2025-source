#include<bits/stdc++.h>
#define int long long
using namespace std;
const int Mod=998244353;
const int N=20;
int vis[N];
int ans=0;
int n,m;
int c[N];
string s;
void dfs(int x,vector<int>v){
	if(x>n){
		int ux=0;
		int num=0;
		for(int i=0;i<n;i++){
			if(s[i]=='0'){ 
				ux++;
				continue;
			}
			if(ux>=v[i]){
				ux++;
				continue;
			}
			num++;
		}

		if(num>=m)ans++;
		ans%=Mod;
		return ;
	}
	
	for(int i = 1;i<=n;i++){
		if(vis[i])continue;
		vis[i]=1;
		v.push_back(c[i]);
		dfs(x+1,v);
		vis[i]=0;
		v.pop_back();
	}
}
void sol1(){
	
}

void sol2(){
	for(int i = 0;i<n;i++){
		if(s[i]=='0'){
			cout<<0;
			return;
		}
	}
	int ans=1;
	for(int i=1;i<=n;i++){
		ans*=i;
		ans%=Mod;
	}
	cout<<ans;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	
	cin>>n>>m;
	

	cin>>s;

	vector<int>v;
	for(int i = 1;i<=n;i++){
		cin>>c[i];
	}
	
	if(m==1){
		sol1();
		return 0;
	}else if(m==n){
		sol2();
		return 0;
	}

	dfs(1,v);
	
	cout<<ans;
	
	return 0;
}
