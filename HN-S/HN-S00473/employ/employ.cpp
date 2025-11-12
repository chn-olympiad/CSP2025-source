#include<bits/stdc++.h>
using namespace std;
int n,m,c[500],vis[500],fr,ans;
string s;
void dfs(int d,int i,int cn){
	if(cn>=m){
		ans++;
		ans%=998244353;
	}
	vis[i]=1;
	int ps=1;
	if(fr>=c[i]||s[d-1]=='0'){
		fr++;
		ps=0;
	}
	for(int j=1;j<=n;j++){
		if(vis[j]==0){
			dfs(d+1,j,cn+ps);
		}
	}
	vis[i]=0;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++)cin>>c[i];
	for(int i=1;i<=n;i++){
		if(s[0]=1){
			dfs(1,i,1);
		}
		else dfs(1,i,0);
	}
	cout<<ans;
	return 0;
}//0
