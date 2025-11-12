#include<bits/stdc++.h>
using namespace std;
int n,m;
char s[100010]; 
int c[1000010];
int a[100010];
int ans;
int st[100010]; 
void dfs(int u,int r){
	if(u==n+1){
		if(r>=m) ans++;
		return;
	}
	for(int i=1;i<=n;i++){
		if(st[i]) continue;
		st[i]=1;
		a[u]=i;
		int nr=r;
		if(u-r-1<c[a[u]]&&s[u-1]=='1') nr++;
		if(n-u+nr<m){
			st[i]=0;
			continue;
		}
		dfs(u+1,nr);
		st[i]=0; 
	} 
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++) cin>>c[i];
	dfs(1,0); 
	cout<<ans;
	return 0;
}
/*
10 5
1101111011
6 0 4 2 1 2 5 4 3 3*/ 
