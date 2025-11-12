#include<bits/stdc++.h>
using namespace std;
const int N=510,MOD=998244353;
int n,m;
string s;
int c[N],vis[N];
int ans=0;
void Dfs(int cur,int sum){
	if(cur>n){
		ans+=(n-sum>=m);
		ans%=MOD;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]==1) continue;
		vis[i]=1;
		if(c[i]<=sum || s[i]=='0'){
			Dfs(cur+1,sum+1);
		}else{
			Dfs(cur+1,sum);
		}
		vis[i]=0;
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	s=" "+s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	Dfs(1,0);
	cout<<ans;
	return 0;
}
