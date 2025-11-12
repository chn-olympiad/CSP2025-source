#include<bits/stdc++.h>
using namespace std;
#define int long long
string s;
const int MOD=998244353;
int a[505];
int c[505];
int cc[505];
int vis[505];
int fac[505];
int len=0,cnt=0;
long long ans=0;
int n,m;
void dfs(int now){
	if(now>n){
		int cntt=0,res=0;
		for(int i=1;i<=n;i++){
			if(s[i-1]=='1'){
				if(cc[i]>cntt){
					res++;
				}
				else cntt++;
			}
			else cntt++;
		}
		if(res>=m) ans++;
		return;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]==0){
			vis[i]=1;
			cc[now]=a[i];
			dfs(now+1);
			vis[i]=0;
		}
	}
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(1);
	cout<<ans;
	
	
	
	return 0;
}
