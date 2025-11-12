#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5,Mod=998244353;
int n,m,ans,c[N];
string s;
bool vis[N];
vector<int>e;
void dfs(int sum){
	if(sum==n){
		int sum2=0,rm=0;
		for(int i=0;i<sum;i++){
			if(sum2<=c[e[i]] && s[i]=='1'){
				rm++;
			}
			else{
				sum2++;
			}
		}
		if(rm>=m){
			ans++;
		}
		
		return;
	}
	for(int i=1;i<=n;i++){
		if(vis[i])continue;
		vis[i]=1;
		e.push_back(i);
		dfs(sum+1);
		e.pop_back();
		vis[i]=0;
	}
}
int main(){
	/*
	3 2 101 1 1 2
	*/
	//freopen("employ.in","r",stdin);
	//freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m>>s;
	for(int i=0;i<n;i++){
		cin>>c[i];
	}
	dfs(0);
	cout<<ans%Mod;
	return 0;
}
