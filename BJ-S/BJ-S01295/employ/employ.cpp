#include<bits/stdc++.h>
using namespace std;
const int M=998244353;
int n,m,ans;
string s;
int c[505],a[505];
bool vis[505];
void dfs(int x,int cnt,int tmp){
	if(x==n+1){
		if(cnt>=m) ans=(ans+1)%M;
		return ;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			if(s[x]=='0' || tmp>=c[i]) dfs(x+1,cnt,tmp+1);
			else dfs(x+1,cnt+1,tmp);
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
	for(int i=1;i<=n;i++) cin>>c[i];
	dfs(1,0,0);
	cout<<ans;
	return 0;
}