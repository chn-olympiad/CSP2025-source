#include<bits/stdc++.h>
#define int long long
using namespace std;

string dif;
int n,tot,ans,k,lq;
int a[100001];int vis[100001];
int mod = 998244353;

int cl(int x){
	int t = 1;
	for(int i = 1;i<=x;i++){
		t*=i;t=t%mod;
	}
	return t;
}

void dfs(int x,int t){
	if(vis[x]) return;
	if(lq>k){
		//cout<<x<<","<<t<<endl;
		ans = (ans+cl(n-t))%mod;
		return;
	}
	if(tot<a[x]&&dif[t]=='1'){
		lq++;
	}
	if(dif[t]=='0') tot++;
	vis[x]=1;
	for(int i = 1;i<=n;i++){
		if(!vis[i]){
			dfs(i,t+1);
		}
	}
	vis[x]=0;
	if(tot<a[x]&&dif[t]=='0'){
		lq--;
	}
	tot--;
}

signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>k;
	cin>>dif;
	for(int i =1;i<=n;i++) cin>>a[i];
	for(int i =1;i<=n;i++){
		lq = 0;tot = 0;
		dfs(i,0);
	}
	cout<<ans<<endl;
}

/*
10 5
1101111011
6 0 4 2 1 2 5 4 3 3
*/
