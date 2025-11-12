#include <bits/stdc++.h>

using namespace std;
const int N=505;
int n,m,c[N],a[N],ans,vis[N];
string s;
void dfs(int x){
	if (x==n){
		int now=0;
		for (int i=1;i<=n;i++){
			if (now>=c[a[i]]||s[i-1]=='0') now++;
		}if (n-now>=m) ans++;
	}
	for (int i=1;i<=n;i++){
		if (!vis[i]){
			vis[i]=1;a[x+1]=i;dfs(x+1);vis[i]=0;
		}
	}
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	cin>>s;
	for (int i=1;i<=n;i++) cin>>c[i];
	dfs(0);
	cout<<ans<<endl;
	return 0;
}
