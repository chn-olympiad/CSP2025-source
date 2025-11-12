#include<bits/stdc++.h>
using namespace std;
const int N = 5e2+10,p = 998244353;
string a;
int c[N],s[N],n,m,ans;
bool vis[N];
void dfs(int x,int y){
	if(y+s[n]-s[x-1]<m) return;
	if(x==n+1){
		if(y>=m) ans++;
		ans%=p;
		return;
	}
	for(int i = 1;i<=n;i++){
		if(vis[i]) continue;
		vis[i] = 1;
		if(c[i]<x-y||a[x]=='0'){
			dfs(x+1,y);
		}else{
			dfs(x+1,y+1);
		}
		vis[i] = 0;
	}
} 
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	cin>>a;
	for(int i = 1;i<=n;i++){
		cin>>c[i];
	} 
	sort(c+1,c+n+1);
	a = ' '+a;
	for(int i = 1;i<=n;i++){
		s[i] = s[i-1];
		if(a[i]=='1') s[i]++;
	}
	dfs(1,0);
	cout<<ans;
	return 0;
} 
