#include<bits/stdc++.h>
using namespace std;
const int N=500+5,mod=998244353;
int n,m;
int s[N];
int c[N];

int vis[N],d[N];
int ans=0;
void dfs(int cur){
	if(cur>n){
		int jian=0;
		for(int i=1;i<=n;i++){
			if(s[i-1]==s[i]) continue;
			if(c[d[i]]<=i-1-(s[i-1]-jian) ) jian++;
		}
		if(s[n]-jian>=m){
			ans++;
			if(ans>mod) ans-=mod;
		}
		return;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]) continue;
		vis[i]=1;
		d[cur]=i;
		dfs(cur+1);
		vis[i]=0;
	}
}

int main(){
	
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		char x;
		cin>>x;
		s[i]+=s[i-1]+(x-'0');//成功人数
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	dfs(1);
	cout<<ans;
	
	return 0;
}
