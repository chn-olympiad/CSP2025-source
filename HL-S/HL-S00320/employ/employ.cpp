#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353;
int n,m;
const int N=505;
int s[N],c[N];
int fac[N];
int ans[N];
int vis[N];
int qwq=0;
void dfs(int now){
	if(now==n+1){
		int sum=0,ret=0;
		for(int i=1;i<=n;i++){
			if(s[i]==0||sum>=c[ans[i]])sum++;
			else ret++;
		}		
		if(ret>=m){
			qwq++;
		}
		return ;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]==0){
			vis[i]=1;
			ans[now]=i;
			dfs(now+1);
			vis[i]=0;
		}
	}
}
signed main(){
	ios::sync_with_stdio(0);cin.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	int cnt=0;
	fac[0]=1;
	for(int i=1;i<=n;i++){
		fac[i]=fac[i-1]%mod*i%mod;
	}
	for(int i=1;i<=n;i++){
		char ch;
		cin>>ch;
		s[i]=ch-'0';
		if(s[i]==1)cnt++;
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	if(cnt==n){
		cout<<fac[n];
		return 0;
	}
	if(n<=20){
		dfs(1);
		cout<<qwq;
	}
	return 0;
}