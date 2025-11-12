#include<iostream>
#include<string>
using namespace std;
int n,m,c[21],ans,vis[21];
string s;
void dfs(int id,int cnt,int cnt2){
	if(id==n+1){
		if(cnt>=m) ans++;
		return;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]==1) continue;
		vis[i]=1;
		if(s[id-1]=='0'||cnt2>=c[i]){
			dfs(id+1,cnt,cnt2+1);
		}
		else{
			dfs(id+1,cnt+1,cnt2);
		}
		vis[i]=0;
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++) cin>>c[i];
	dfs(1,0,0);
	cout<<ans;
	return 0;
}
