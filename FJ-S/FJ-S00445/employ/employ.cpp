#include<bits/stdc++.h>
using namespace std;
const int N=505;
const int mod=998244353;
int n,m,a[N];
string s;
long long ans;
int vis[N],b[N];
bool check(){
	int nont=0,knt=0;
	for(int i=1;i<=n;i++){
		if(s[i-1]=='0' || nont>=a[b[i]]) nont++;
		else knt++;
	}
	if(knt>=m) return true;
	return false;
}
void dfs(int x){
	if(x>n){
		if(check()) ans=(ans+1)%mod;
		return ;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]==1) continue;
		vis[i]=1;
		b[x]=i;
		dfs(x+1);
		vis[i]=0;
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++) cin>>a[i];
	bool flag=1;
	for(int i=1;i<=n;i++){
		if(s[i-1]=='0'){
			flag=0;
			break;
		}
	}
	if(flag){
		long long res=1;
		for(int i=1;i<=n;i++){
			res=(res*(long long)(i))%mod;
		}
		cout<<res;
		return 0;
	}
	dfs(1);
	cout<<ans;
	return 0;
}
