#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,ans;
int c[505],vis[505];
string s;
map<vector<int>,int>mp;
vector<int>v;
void dfs(int x,int cnt){
	if(x>n){
		if(cnt-1<m) return;
		int tmp(cnt-1),sum(s[0]=='0');
		for(int i=1;i<v.size();++i){
			if(sum>=c[v[i]]){
				tmp--;
				sum++;
			}
			if(s[i]=='0') sum++;
		}
		if(tmp>=m and !mp[v]++) ans++;
		return;		
	}
	dfs(x+1,cnt);
	for(int i=1;i<=n;++i){
		if(!vis[i]){
			vis[i]=1;	
			v.push_back(i);
			dfs(x+1,cnt+1);
			vis[i]=0;
			v.pop_back(); 
		}
	}
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;++i) cin>>c[i];
	dfs(1,0);
	cout<<ans;
}
