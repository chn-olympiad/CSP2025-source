#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N=5005;
const ll mod=998244353;
int n,a[N],ans;
bool vis[N];
void dfs(int id,int sum,int k){
	if(id>n) return;
	if(k>=3&&sum>a[id]*2) ans=(ans+1)%mod;
	dfs(id+1,sum+a[id+1],k+1);
	dfs(id+1,sum,k);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);

	cin>>n;
	for(int i=1;i<=n;++i) cin>>a[i];
	dfs(0,0,0);
	cout<<ans;
}
