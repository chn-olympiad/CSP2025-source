#include<bits/stdc++.h>
#define FILE(x) freopen(x".in","r",stdin);freopen(x".out","w",stdout)
using namespace std;
const int Mod=998244353;
const int N=114;
int n,m,ans;
int c[N],vis[N],pos[N];
string s;
void dfs(int now){
	if(now>n){
		int sum=0;
		for(int i=1;i<=n;i++){
			if(s[i-1]=='0'||sum>=c[pos[i]]) sum++;
		}
		if(n-sum>=m) ans=(ans+1)%Mod;
		return ;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]==0){
			vis[i]=1;
			pos[now]=i;
			dfs(now+1);
			vis[i]=0;
		}
	}
}
int main(){
	FILE("employ");
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	dfs(1);
	cout<<ans;
	return 0;
}
