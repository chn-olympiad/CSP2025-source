#include<bits/stdc++.h>
using namespace std;

int n,m,a[510],p[510],w[510],res,used[510];
string s;
const int mod=998244353;

void dfs(int x){
	if(x>n){
		int cnt=0,ans=0;
		for(int i = 1;i <= n;i++){
			if(w[i]&&a[p[i]]>cnt) ans++;
			else cnt++;
		}
		if(ans>=m) res++;
		res%=mod;
		return;
	}for(int i = 1;i <= n;i++)if(!used[i]){
		used[i]=1;
		p[x]=i;
		dfs(x+1);
		used[i]=0;
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i = 0;i < n;i++) w[i+1]=s[i]-'0';
	for(int i = 1;i <= n;i++) cin>>a[i];
	dfs(1);
	cout<<res<<'\n';
	return 0;
}

