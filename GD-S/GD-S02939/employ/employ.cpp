#include<bits/stdc++.h>
#define INF 2e18
#define fi first
#define se second
#define endl '\n'
#define int long long
#define mem(x,v) memset(x,v,sizoef x)
using namespace std;
const int N = 505;
const int MOD = 998244353;

int n,m,c[N],ans;
string s;
int num[N],vis[N];

void dfs(int stp){
	if(stp==n+1){
		int tot1=0,tot2=0;
		for(int i=1;i<=n;i++){
			int x=num[i];
			if(tot1>=c[x]||s[i]=='0'){
				tot1++;
				continue;
			}
			tot2++;
		}
		if(tot2>=m)ans++;
		return;
	}
	for(int i=1;i<=n;i++){
		if(vis[i])continue;
		vis[i]=1,num[stp]=i;
		dfs(stp+1);
		vis[i]=0;
	}
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m>>s,s=' '+s;
	for(int i=1;i<=n;i++)cin>>c[i];
	dfs(1),cout<<ans%MOD;
	return 0;
} 
/*
17:37 1,2 8pts
*/
