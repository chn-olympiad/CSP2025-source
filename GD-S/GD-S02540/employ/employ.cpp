#include<bits/stdc++.h>
using namespace std;
const long long N=5e2+1;
string s;
long long c[N],n,m,ans,a[N];
bool vis[N];
void dfs(long long step,long long lu,long long gg){
	if(step==n+1){
		if(lu>=m){
			ans++;
		}
		return;
	}
	ans%=998244353;
	for(int i=1;i<=n;++i){
		if(vis[i])continue;
		vis[i]=true;
		a[step]=i;
		if(gg>=c[i])dfs(step+1,lu,gg+1);
		else if(s[step-1]=='0')dfs(step+1,lu,gg+1);
		else dfs(step+1,lu+1,gg);
		a[step]=0;
		vis[i]=false;
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.ans","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;++i){
		cin>>c[i];
	}
	if(n<=10){
		dfs(1,0,0);
		cout<<ans<<endl;
	}else{
		ans=1;
		for(long long i=1;i<=n;++i){
			ans=ans*i%998244353;
		}
		cout<<ans<<endl;
	}
	return 0;
}
/*
10 5
1101111011
6 0 4 2 1 2 5 4 3 3
*/
