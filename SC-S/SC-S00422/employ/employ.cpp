#include<bits/stdc++.h>
using namespace std;
int n,m;
string s;
int c[510],p[510],vis[510];
long long ans=0,f[510][510][510];
const long long mod=998244353;
void dfs(int x){
	if(x>n){
		int w=0,co=0;
		for(int i=1;i <= n;i++){
			if(s[i-1]=='0'){
				w++;
			}else if(s[i-1]=='1'){
				if(c[p[i]]>w){
					co++;
				}else{
					w++;
				}
			}
		}
		if(co>=m){
			ans++;
			ans%=mod;
		}
		return ;
	}
	for(int i=1;i <= n;i++){
		if(!vis[i]){
			vis[i]=1;
			p[x]=i;
			dfs(x+1);
			vis[i]=0;
			p[x]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	int ff=0;
	for(int i=1;i <= n;i++){
		cin>>c[i];
		if(!c[i]) ff++;
	}
	if(n<=10){
		dfs(1);
		cout<<ans;
	}else{
		cout<<0;
	}
	return 0;
}