#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
bool a[100001];
int b[100001],n,m;
int v[100001];
int dfs(int x,int u,int t){
	if(x==n+1){
		if(u>=m)
			return 1;
		else
			return 0;
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		if(v[i]==0){
			v[i]=1;
			if(a[x]==0||t>=b[i]) ans+=dfs(x+1,u,t+1)%mod;
			else ans+=dfs(x+1,u+1,t)%mod;
			v[i]=0;
		}
	}
	return ans%mod;
}
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
	cin>>n>>m;
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++)
		a[i+1]=s[i]-'0';
	for(int i=1;i<=n;i++)
		cin>>b[i];
	cout<<dfs(1,0,0)%mod;
	return 0;
}
