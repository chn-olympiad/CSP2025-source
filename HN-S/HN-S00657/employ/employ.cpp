#include<bits/stdc++.h>
using namespace std;
int n,m;
const long long  md=998244353;
int c[105],vis[105];
int a[105];
string s;
long long ans=0;
bool ck(){
	long long sum=0,d=0;
	for(int i=1;i<=n;i++){
		if(sum>=m) return 1;
		if(s[i]=='0'){
			d++;
			continue;
		}
		else{
			if(d<c[a[i]]) sum++;
			else d++;
		}
	}
	if(sum>=m) return 1;
	return 0;
}
void dfs(int x){
	if(x==n+1){
		if(ck()){
			ans=(ans+1)%md;
		}
		return;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]) continue;
		a[x]=i;
		vis[i]=1;
		dfs(x+1);
		vis[i]=0;
	}
	return ;
} 
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	s=' '+s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	dfs(1);
	cout<<ans;
	return 0;
}
