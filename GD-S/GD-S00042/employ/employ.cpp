#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=5e2+5,P=998244353;
int n,m,p[MAXN];
string s;
ll ans;
bool vis[MAXN];
inline void dfs(int pos,int a,int b){
	if(pos==n){
		if(a>=m)ans=(ans+1)%P;
		return;
	}
	for(int i=1;i<=n;i++){
		if(vis[i])continue;
		vis[i]=1;
		if(p[i]<=b||s[pos]=='0')dfs(pos+1,a,b+1);
		else dfs(pos+1,a+1,b);
		vis[i]=0;
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++){
		cin>>p[i];
	}
	if(n<=20){
		dfs(0,0,0);
	}
	cout<<ans;
}
