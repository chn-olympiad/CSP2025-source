#include<bits/stdc++.h>
using namespace std;

int n,m;
long long cnt = 0;
int f[505],vis[505];
char s[505];
long long p = 998244353;

int dfs(int i,int l,int q,int qu){
	if(vis[i])
		return 0;
	vis[i] = 1;
	if(q >= f[i] || s[l] == '0'){
		q++;
	}
	else qu++;
	if(l == n){
		if(qu >= m){
			cnt++;
			cnt %= p;
		}
	}
	for(int j=1;j<=n;j++){
		dfs(j,l+1,q,qu);
	}
	vis[i] = 0;
}

int main(){
	
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s[i];
	}
	for(int i=1;i<=n;i++){
		cin>>f[i];
	}
	for(int i=1;i<=n;i++){
		dfs(i,1,0,0);
	}
	cout<<cnt;
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
