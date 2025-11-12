#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e6+5;
int n,a[N];
int vis[N];
ll ans,maxn;
const ll mod = 998244353;
void dfs(int k){
	if(k==n+1){
		int m = 0,sum=0,maxn=0;
		for(int i=1;i<=n;i++){
			//cout<<vis[i]<<" ";
			//cout<<endl;
			if(vis[i]){
				m++;
				maxn=max(maxn,a[i]);
				sum+=a[i];
			}
		}
		if(m>=3&&sum>maxn*2)ans++;
		
		return;
	}
	for(int i=0;i<=1;i++){
		vis[k]=i;
		dfs(k+1);
		vis[k]=0;
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(1);
	cout<<ans%mod;
	return 0;
}

