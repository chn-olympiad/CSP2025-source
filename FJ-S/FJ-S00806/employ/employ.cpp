#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long c[501],vis[501];
string s;
long long ans=0;
void dfs(int alin,int alha){
	if(alin==n){
		if(alha>=m) ans++;
		return;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]==0){
			vis[i]=1;
			if(alin-alha<=c[i]) dfs(alin+1,alha+(s[alin+1]-'0'));
			else dfs(alin+1,alha);
			vis[i]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	cin>>s;
	for(long long i=1;i<=n;i++){
		scanf("%lld",&c[i]);
	}
	dfs(0,0);
	printf("%lld\n",ans%998%244%353);
	return 0;
}

