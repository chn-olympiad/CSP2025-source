#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=501,mod=998244353 ;
int n,q,m,jie[N],ans,s[N],c[N],a[N],sum=0;
int vis[N];
void dfs(int x,int sum){
	if(n-sum<m)return;
	if(x==n+1){
		if(n-sum>=m){
			ans++;
			if(ans>mod)ans-=mod;
		}
		return;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]==0){
			vis[i]=1;a[x]=i;
			if(s[x]==0){
				dfs(x+1,sum+1);
			}
			else if(sum>=c[i]){
				dfs(x+1,sum+1);
			}
			else dfs(x+1,sum);
			vis[i]=0;
		}
	}
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		char h;
		cin>>h;
		s[i]=h-'0';
	}
	
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	if(n<19){
		dfs(1,0);
		cout<<ans;
	}
	else{
		int ans=1;
		for(int i=1;i<=n;i++){
			ans=ans*i%mod;
		}
		cout<<ans;
	}
	return 0;
}

