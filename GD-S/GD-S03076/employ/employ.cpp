#include<bits/stdc++.h>
using namespace std;
bool flag[510];
bool flag2[510];
int C[510];
int ans;
const int mod=998244353;
int n,m;
void dfs(int t,int fi,int sum){
	if(t>n){
		if(sum>=m){
			ans++;
			ans%=mod;
		}
		return;
	}
	if(n-fi<m) return;
	for(int i=1;i<=n;i++){
		if(!flag2[i]){
			flag2[i]=1;
			if(flag[t]&&fi<C[i]) dfs(t+1,fi,sum+1);
			else dfs(t+1,fi+1,sum);
			flag2[i]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin>>n>>m;
	string s;
	cin>>s;
	for(int i=0;i<s.length();i++){
		flag[i+1]=s[i]-'0';
	}
	for(int i=1;i<=n;i++){
		cin>>C[i];
	}
	dfs(1,0,0);
	cout<<ans;
	return 0;
} 
