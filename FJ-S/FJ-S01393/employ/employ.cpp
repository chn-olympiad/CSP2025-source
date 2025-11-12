#include<bits/stdc++.h>
using namespace std;
#define int long long
#define INF 0x3f3f3f3f3f3f3f3f
#define endl '\n'
const int mod=998244353;
int n,m,c[510],a[510],vis[510],ans;
string s;
void dfs(int k){
	if(k==n+1){
		int num=0,sum=0;
		for(int i=1;i<=n;i++)
			if(s[i]=='1'&&sum<=c[a[i]])
				num++;
			else sum++;
		if(num>=m){
			++ans,ans%=mod;
		}
		return;
	}
	for(int i=1;i<=n;i++)
		if(!vis[i]){
			vis[i]=1;
			a[k]=i;
			dfs(k+1);
			vis[i]=0;
		}
}
void solve(){
	cin>>n>>m>>s;
	s='?'+s;
	for(int i=1;i<=n;i++)
		cin>>c[i];
	dfs(1);
	cout<<ans;
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int num=1;
	//cin>>num;
	while(num--)solve();
	return 0;
}
