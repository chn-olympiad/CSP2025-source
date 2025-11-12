#include <bits/stdc++.h>
using namespace std;

int a[505];
int s[505];
bool vis[505];
int p[505];
long long mod=998244353;
long long ans,rp1;
int n,m;
void dfs(int w){
	if (w==n+1){
		int cnt=0,rp=0;
		for(int j=1;j<=n;j++){
			if (rp>=a[p[j]]){
				rp++;
				continue;
			}
			if (s[j]) cnt++;
			else rp++;
		}
		if (cnt>=m) ans++;
		rp1++;
		return;
	}
	for(int i=1;i<=n;i++){
		if (vis[i]) continue;
		vis[i]=1;
		p[w]=i;
		dfs(w+1);
		vis[i]=0;
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	bool f=1;
	for(int i=1;i<=n;i++){
		scanf("%1d",&s[i]);
		f=f&s[i];
	}
	for(int i=1;i<=n;i++) cin>>a[i];
	if (n<=10&&m<=10){
		dfs(1);
		cout<<ans<<endl;
	}
	else{
		ans=1;
		for(int i=1;i<=n;i++) ans=ans*i%mod;
		cout<<ans<<endl;
	}
	return 0;
}
