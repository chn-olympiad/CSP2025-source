#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
char ta[11000];
ll a[11000],kl[11000],sum,b[11000];
bool vis[11000];
ll n,m;
void dfs(ll cur){
	if(cur>n){
		ll op=0,tt=0;
		for(ll i=1;i<=n;i++){
			if(a[i]==0){
				tt++;
				continue;
			}
			if(tt<kl[b[i]]){
				op++;
			}
		}
		
		if(op>=m){
			sum++;
		}
		sum%=998244353;
	}
	for(ll i=1;i<=n;i++){
		if(vis[i]==0){
			vis[i]=1;
			b[cur]=i;
			dfs(cur+1);
			vis[i]=0;
			b[cur]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>ta[i];
		a[i]=ta[i]-'0';
	}
	for(ll i=1;i<=n;i++){
		cin>>kl[i];
	}
	dfs(1);
	cout<<sum;
	return 0;
}
