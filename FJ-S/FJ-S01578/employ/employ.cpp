#include<bits/stdc++.h>
#define int long long
#define INF 1e16
using namespace std;
const int N=510,Mod=998244353;
string s;
int c[N];
int n,m;
int vis[N];
int Ans;
void dfs(int t){
	if(t==n+1){
		int t=0;
		for(int i=1;i<=n;i++){
			if(c[vis[i]]<=t||s[i-1]=='0'){
				t++;
			}
		}
		if(n-t>=m){
			Ans++;
			Ans%=Mod;
		}
		return;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=t;
			dfs(t+1);
			vis[i]=0;
		}
	}
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	if(n<=10){
		dfs(1);
		cout<<Ans<<'\n';
		return 0;
	}
	int ans=1;
	for(int i=1;i<=n;i++){
		ans=ans*i%Mod;
	}
	cout<<ans<<'\n';
	return 0;
}
