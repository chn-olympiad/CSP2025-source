#include<bits/stdc++.h>
using namespace std;
const int N=505;
int n,m,ans;
char c;
int a[N]={1e9};
bool s[N],vis[N];	//fail
void dfs(int pos,int f){
	if(n-f<m) return ;
	if(pos>n){
		++ans;
		return ;
	}
	for(int i=1;i<=n;++i){
		if(vis[i]) continue;
		vis[i]=true;
		if(f<a[i] && s[pos]) dfs(pos+1,f);
		else dfs(pos+1,f+1);
		vis[i]=false;
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>c;
		if(c=='1') s[i]=true;
	}
	for(int i=1;i<=n;++i) cin>>a[i];
	dfs(1,0);
	cout<<ans;
	return 0;
} 
