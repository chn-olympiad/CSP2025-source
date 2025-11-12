#include<bits/stdc++.h>
using namespace std;
int n,m,ans;
string s;
int c[1024];
vector<int> daoc[1024];
bool vis[1024];
void dfs(int d,int cnt){
	if(d>n) return;
	if(d-cnt>=m) ans++;
	for(int i=1;i<=n;i++){
		if(vis[i]!=1&&cnt<c[i]){
			vis[i]=1;
			if(s[i]=='0') dfs(d+1,cnt+1);
			else dfs(d+1,cnt);
			vis[i]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	s=' '+s;
	for(int i=1;i<=n;i++) cin>>c[i],daoc[c[i]].push_back(i);
	dfs(1,0);
	cout<<ans;
	return 0;
}
