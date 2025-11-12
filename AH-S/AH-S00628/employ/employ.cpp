#include<bits/stdc++.h>
using namespace std;
int n,m,c[510],ans=0;
string s;
string sx;
int vis[510];
const int mod=998244353;
void dfs(int x){
	if(x>n){
		int now=0;
		for(int i=0;i<sx.size();i++){
			if(now>=c[sx[i]-'0']||s[i]=='0'){
				now++;
				continue;
			}
		}
		if(n-now>=m){
			ans=(ans+1)%mod;
		}
		return;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			char c=i+'0';
			sx=sx+c;
			dfs(x+1);
			vis[i]=0;
			sx.pop_back();
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >>n>>m>>s;
	for(int i=1;i<=n;i++)
		cin >>c[i];
	dfs(1);
	cout<<ans;
	return 0;
}
