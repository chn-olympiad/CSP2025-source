#include <iostream>
#include <string>
#include <cstring>
#define int long long
using namespace std;
const int mod=998244353,N=510;
int n,m,ans,vis[N],a[N],O[N];
string s;
void dfs(int sum,int now) {
	if(now==s.length()) {
		if(sum>=m)ans++;
		return;
	}
	if(O[s.length()]-O[now]<m-sum)return;
	for(int i=1;i<=n;i++) {
		if(vis[i])continue;
		vis[i]=1;
		if(s[now]=='0'||now-sum>=a[i])dfs(sum,now+1);
		else dfs(sum+1,now+1);
		vis[i]=0;
	}
}
signed main() {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=s.length();i++)O[i]=O[i-1]+(s[i-1]=='1');
	for(int i=1;i<=n;i++)cin>>a[i];
	dfs(0,0);
	cout<<ans;
	return 0;
}
