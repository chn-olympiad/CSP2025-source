#include<bits/stdc++.h>
using namespace std;
int n,m;
string s;
int a[10005];
int p;
bool flag[10005];
int ans;
void dfs(int x){
	if(n-p<m)return ;
	if(x==n+1){
		ans++;
		return ;
	}
	for(int i=1;i<=n;i++){
		if(flag[i]==1)continue;
		int pp=p;
		if(s[x]=='0'||a[i]<=p)p++;
		flag[i]=1;
		dfs(x+1);
		p=pp;
		flag[i]=0;
	}
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	s=' '+s;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(1);
	cout<<ans;
	return 0;
}

