#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int t,n,a[N],p[N],m,ans;
bool vis[N];
string s;
void dfs(int x){
	if(x==n+1){
		int cnt=0;
		for(int i=1;i<=n;i++){
		    if(cnt>=a[p[i]]||s[i-1]=='0') cnt++;  
		}
		if(n-cnt>=m) ans++;
		ans%=998244353;
		return;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			p[x]=i;
			dfs(x+1);
			vis[i]=0;
		}
	}
}
int main () {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++) cin>>a[i]; 
	dfs(1);
	cout<<ans;
	return 0;
} 
