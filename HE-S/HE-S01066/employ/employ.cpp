#include<bits/stdc++.h>

using namespace std;

int n,m,ans,p[505],c[505];
char s[505];
bool k[505];

inline void dfs(int x){
	if(x>n){
		int q=0,sum=0;
		for(int i=1;i<=n;++i){
			if(s[i-1]=='0'||c[p[i]]<=q)++q;
			else++sum;
		}
		if(sum>=m)++ans,ans%=998244353;
		return;
	}
	for(int i=1;i<=n;++i){
		if(k[i]==0){
			k[i]=1;
			p[x]=i;
			dfs(x+1);
			k[i]=0;
			p[x]=0;
		}
	}
}

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;++i)cin>>c[i];
	dfs(1);
	cout<<ans;
}
