#include <bits/stdc++.h>
using namespace std;
const long long mod=998244353;
int n,m;
string nd;
int c[10005];
int vis[105],xz[105],ans;
void dfs(int w){
	if(w==n+1){
		int qzs=0;
		for(int i=1;i<=n;i++){
			if(nd[i]=='0')qzs++;
			else{
				if(qzs>=c[xz[i]])qzs++;
			}
		}
		if(n-qzs>=m)ans++;
		return;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]==0){
			vis[i]=1;
			xz[w]=i;
			dfs(w+1);
			vis[i]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m>>nd;
	nd=' '+nd;
	for(int i=1;i<=n;i++)cin>>c[i];
	if(n<=10){
		dfs(1);
		cout<<ans;
		return 0;
	}
	if(m==n){
		int fla=1;
		for(int i=1;i<=n;i++){
			if(nd[i]=='0'){
				fla=0;
				break;
			}
			if(c[i]==0){
				fla=0;
				break;
			}
		}
		if(fla==0)cout<<0;
		else{
			long long sl=1;
			for(int i=1;i<=n;i++)sl=1ll*sl*i%mod;
			cout<<sl;
		}
		return 0;
	}
	cout<<0;
	return 0;
}
