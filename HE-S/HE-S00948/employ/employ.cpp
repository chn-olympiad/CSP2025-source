#include <bits/stdc++.h>
using namespace std;
int n,m;
char ch;
int q[505],c[505],s[505],ans;
bool f[505];
inline void dfs(int x){
	if(x>n){
		for(int i=1;i<=n;i++){
			if(c[s[i]]<=q[i-1]) return;
		}
		ans++;
		ans%=998244353;
		return;
	}
	for(int i=1;i<=n;i++){
		if(f[i]){
			f[i]=false;
			s[x]=i;
			dfs(x+1);
			f[i]=true;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	string s;
	cin>>s;
	for(int i=1;i<=n;i++){
		q[i]=q[i-1]+((s[i-1]-'0')!=1);
	}
	for(int i=1;i<=n;i++){
		f[i]=true;
		cin>>c[i];
	}
	dfs(1);
	cout<<ans;
	return 0;
}
